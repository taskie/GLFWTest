//
//  Mixer.h
//  GLFWTest
//
//  Created by taskie on 2012/12/19.
//  Copyright (c) 2012年 alprosys. All rights reserved.
//

#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include "../al/Source.h"
#include "MediaFile.h"

namespace aps
{
	namespace sound
	{
		class SoundBase
		{
		public:
			SoundBase(std::string path) : file_(path) { }
			virtual ~SoundBase() { }
			
			virtual bool update() = 0;
			
			virtual void play() { source_.play(); }
			virtual void pause() { source_.pause(); }
			virtual void stop() { source_.stop(); }
			virtual void rewind() { source_.rewind(); }
			
			bool isInitial() const { return source_.isInitial(); }
			bool isPlaying() const { return source_.isPlaying(); }
			bool isPaused() const { return source_.isPaused(); }
			bool isStopped() const { return source_.isStopped(); }
			
		protected:
			al::Source& source() { return source_; }
			MediaFile& file() { return file_; }
			
		private:
			al::Source source_;
			MediaFile file_;
		};
		
		class Sound : public SoundBase
		{
		public:
			Sound(std::string path)
			: SoundBase(path)
			{
				al::Buffer buffer;
				if (file().bad()) return;
				std::vector<std::int16_t> data = file().readAll();
				if (data.empty()) return;
				buffer.setData(&data[0], data.size(), file().rate(), file().isStereo());
				source().setBuffer(buffer);
			}
			
			bool update()
			{
				if (source().isStopped()) return false;
				return true;
			}
		};
		
		class Music : public SoundBase
		{
		public:
			Music(std::string path)
			: SoundBase(path)
			{
				update();
			}
			
			bool update()
			{
				source().popProcessedBuffers();
				
				if (source().isStopped()) return false;
				
				while (source().unprocessedBuffersLength() < 5)
				{
					al::Buffer buffer;
					if (file().bad()) break;
					std::vector<std::int16_t> data = file().read(file().rate() * file().channels());
					if (data.empty()) break;
					buffer.setData(&data[0], data.size(), file().rate(), file().isStereo());
					source().pushBuffer(buffer);
				}
				
				return true;
			}
			
			virtual void rewind()
			{
				file().rewind();
				source().clearBuffers();
				update();
			}
		};
		
		class Mixer
		{
		public:
			void loadMusic(std::string key, std::string path)
			{
				soundDictionary_[key] = std::unique_ptr<Music>(new Music(path));
			}
			
			void loadSound(std::string key, std::string path)
			{
				soundDictionary_[key] = std::unique_ptr<Sound>(new Sound(path));
			}
			
			void play(std::string key) {
				auto it = soundDictionary_.find(key);
				if (it != soundDictionary_.end()) it->second->play();
			}
			
			void pause(std::string key) {
				auto it = soundDictionary_.find(key);
				if (it != soundDictionary_.end()) it->second->pause();
			}
			
			void stop(std::string key) {
				auto it = soundDictionary_.find(key);
				if (it != soundDictionary_.end()) it->second->stop();
			}
			
			void rewind(std::string key) {
				auto it = soundDictionary_.find(key);
				if (it != soundDictionary_.end()) it->second->rewind();
			}
			
			void update() {
				for (auto& pair : soundDictionary_) pair.second->update();
			}
			
		private:
			std::unordered_map<std::string, std::unique_ptr<SoundBase>> soundDictionary_;
		};
	}
}