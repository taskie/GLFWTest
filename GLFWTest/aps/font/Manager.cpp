#include "Manager.h"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <unordered_map>
#include <exception>
#include <stdexcept>

namespace aps
{
	namespace font
	{
		class Library
		{
		public:
			Library()
			: libraryPtr_(new FT_Library(), [](FT_Library* ptr){
				FT_Done_FreeType(*ptr);
				delete ptr;
			})
			{
				const FT_Error initError = FT_Init_FreeType(libraryPtr_.get());
				if (initError)
				{
					throw std::runtime_error("FT_Init_FreeType failed.");
				}
			}
			
			FT_Library get() { return *libraryPtr_; }
			
		private:
			std::shared_ptr<FT_Library> libraryPtr_;
		};
		
		class Face
		{
		public:
			Face()
			: facePtr_(nullptr)
			{
				
			}
			
			Face(Library library, std::string filePath, FT_Long faceIndex)
			: facePtr_(new FT_Face(), [](FT_Face* ptr){
				FT_Done_Face(*ptr);
				delete ptr;
			})
			{
				const FT_Error faceError = FT_New_Face(library.get(), filePath.c_str(),
													   faceIndex, facePtr_.get());
				if (faceError)
				{
					throw std::runtime_error("Face (" + filePath + ") initialize failed.");
				}
			}
			
			FT_Face get() { return *facePtr_; }
			
		private:
			std::shared_ptr<FT_Face> facePtr_;
		};
	}
}

using namespace aps::font;

// Manager::Impl

class Manager::Impl
{
public:
	Impl()
	{
		
	}
	
	bool loadFont(std::string name, std::string filePath, FT_Long faceIndex)
	{
		try
		{
			Face face(library_, filePath, faceIndex);
			faceDictionary_[name] = face;
		}
		catch (std::runtime_error e)
		{
			errorMessage_ = e.what();
			return false;
		}
		return true;
	}
	
	GlyphBitmap getGlyphBitmap(std::string name, FT_ULong charCode, int size)
	{
		auto keyFacePairIter = faceDictionary_.find(name);
		if (keyFacePairIter == faceDictionary_.end())
		{
			return GlyphBitmap(0, 0, 0, 0, 0, 0, 0);
		}
		
		auto face = keyFacePairIter->second.get();
		FT_UInt index = FT_Get_Char_Index(face, charCode);
		
		FT_Set_Char_Size(face, 0, size << 6, 0, 0);
		FT_Load_Glyph(face, index, FT_LOAD_RENDER);
		
		const auto& glyph = face->glyph;
		const auto& bitmap = glyph->bitmap;
		
		return GlyphBitmap(bitmap.buffer, bitmap.width, bitmap.rows,
						   glyph->bitmap_left, glyph->bitmap_top, bitmap.pitch, glyph->advance.x >> 6);
	}
	
	double kerning(std::string name, FT_UInt left, FT_UInt right, int size)
	{
		auto facePairIter = faceDictionary_.find(name);
		if (facePairIter == faceDictionary_.end()) return 0;
		auto face = facePairIter->second.get();
		if (!FT_HAS_KERNING(face)) return 0;
		
		FT_Set_Char_Size(face, 0, size << 6, 0, 0);
		FT_Vector delta;
		FT_Get_Kerning(face, left, right, FT_KERNING_DEFAULT, &delta);
		
		return delta.x >> 6;
	}
	
	std::string errorMessage() const { return errorMessage_; }
	
	void errorClear() { errorMessage_ = ""; }
	
private:
	Library library_;
	std::unordered_map<std::string, Face> faceDictionary_;
	std::string errorMessage_;
};

Manager::Manager()
: pImpl(new Impl())
{
	
}

bool Manager::loadFont(std::string name, std::string filePath, long faceIndex)
{
	return pImpl->loadFont(name, filePath, faceIndex);
}

GlyphBitmap Manager::getGlyphBitmap(std::string name, unsigned long charCode, int size)
{
	return pImpl->getGlyphBitmap(name, charCode, size);
}

double Manager::kerning(std::string name, unsigned int left, unsigned int right, int size)
{
	return pImpl->kerning(name, left, right, size);
}

std::string Manager::errorMessage() const { return pImpl->errorMessage(); }

void Manager::errorClear() { return pImpl->errorClear(); }