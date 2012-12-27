#pragma once

#include <string>
#include <vector>
#include <memory>
#include <boost/algorithm/string.hpp>

#include "Wave.h"
#include "Vorbis.h"

namespace aps
{
	namespace sound
	{
		class MediaFile
		{
			struct FileHolderBase
			{
				FileHolderBase() { }
				virtual ~FileHolderBase() { }
				virtual void rewind() = 0;
				virtual std::vector<std::int16_t> read(std::size_t size) = 0;
				virtual std::vector<std::int16_t> readAll() = 0;
				virtual long rate() const = 0;
				virtual int channels() const = 0;
				virtual bool isStereo() const = 0;
				virtual bool bad() const = 0;
			};
			
			template <class T>
			class FileHolder : public FileHolderBase
			{
			public:
				FileHolder(T& file) : file_(file) { }
				virtual ~FileHolder() { }
				virtual void rewind() { file_.rewind(); }
				virtual std::vector<std::int16_t> read(std::size_t size) { return file_.read(size); }
				virtual std::vector<std::int16_t> readAll() { return file_.readAll(); }
				virtual long rate() const { return file_.rate(); }
				virtual int channels() const { return file_.channels(); }
				virtual bool isStereo() const { return file_.isStereo(); }
				virtual bool bad() const { return file_.bad(); }
			private:
				T file_;
			};
			
		public:
			MediaFile(std::string path)
			: bad_(false)
			{
				if (boost::algorithm::iends_with(path, ".wav")) {
					WaveFile wave(path);
					pFileHolder_.reset(new FileHolder<WaveFile>(wave));
				}
				else if (boost::algorithm::iends_with(path, ".ogg")) {
					VorbisFile vorbis(path);
					pFileHolder_.reset(new FileHolder<VorbisFile>(vorbis));
				}
				else {
					bad_ = true;
				}
			}
			
			template <class T>
			MediaFile(T file)
			{
				pFileHolder_.reset(new FileHolder<T>(file));
			}
			
			void rewind() { pFileHolder_->rewind(); }
			std::vector<std::int16_t> read(std::size_t size) { return pFileHolder_->read(size); }
			std::vector<std::int16_t> readAll() { return pFileHolder_->readAll(); }
			long rate() { return pFileHolder_->rate(); }
			int channels() { return pFileHolder_->channels(); }
			bool isStereo() { return pFileHolder_->isStereo(); }
			bool bad() { return bad_ || pFileHolder_->bad(); }
			
		private:
			std::shared_ptr<FileHolderBase> pFileHolder_;
			bool bad_;
		};
	}
}