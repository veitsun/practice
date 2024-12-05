#include "CacheFile.h"
#include <cstring>
#include <iostream>

// 打开读文件
bool CacheFile::openFileForRead() {
  inputfile.open(fileName, ios::in | ios::binary);
  return inputfile.is_open();
}

// 打开写文件
bool CacheFile::openFileForWrite() {
  outputfile.open(fileName, ios::out | ios::binary | ios::app);
  return outputfile.is_open();
}

// read操作
size_t CacheFile::read(char *destination, size_t size) {
  size_t totalRead = 0;
  if (buffer_Position == 0) {
    inputfile.read(buffer.data(), bufferSize); // 读满 先存着
  }

  while (totalRead < size) {

    if (buffer_Position == bufferSize) {
      // 缓存区数据已读完，从文件重新填充缓存区
      inputfile.read(buffer.data(), bufferSize);
      size_t bytesRead = inputfile.gcount();
      if (bytesRead == 0) {
        // 文件结束，返回已读取的字节数
        return totalRead;
      }
      buffer_Position = 0;
    }
    // 将缓存区中的数据复制到目标缓存区
    size_t remainingbuffer = buffer.size() - buffer_Position;
    size_t to_copy = std::min(remainingbuffer, size - totalRead);

    std::memcpy(destination + totalRead, buffer.data() + buffer_Position,
                to_copy);
    totalRead += to_copy;
    buffer_Position += to_copy;
  }

  return totalRead;
}

// write操作
size_t CacheFile::write(const char *data, size_t numbytes) {
  size_t totalWrite = 0;

  while (totalWrite < numbytes) {

    size_t remainingbuffer = bufferSize - buffer_Position;
    size_t data_to_buffer = std::min(remainingbuffer, numbytes - totalWrite);
    std::memcpy(buffer.data() + buffer_Position, data + totalWrite,
                data_to_buffer);

    totalWrite += data_to_buffer;
    buffer_Position += data_to_buffer;

    if (buffer_Position == bufferSize) // 假设写满缓冲区后才往文件中写入
    {
      outputfile.write(buffer.data(), bufferSize);
      buffer.clear();
      buffer_Position = 0;
    }

    // 数据量过少
    if (buffer_Position < bufferSize && buffer_Position > 0) {
      // flushBuffer();
      break;
    }
  }
  return totalWrite;
}

// 手动保存缓冲区数据到文件中
void CacheFile::flushBuffer() {
  if (outputfile.is_open()) {
    outputfile.write(buffer.data(), buffer_Position);
    buffer.clear();
    buffer_Position = 0;
  } else {
    cout << "手动保存数据失败" << endl;
  }
}

// lseek操作 offset:偏移量 whence:什么方式进行偏移
std::streampos CacheFile::lseek(std::streampos offset,
                                std::ios_base::seekdir whence) {
  std::streampos currentPos;
  if (whence == std::ios_base::cur) {
    currentPos = inputfile.tellg(); // 获取当前读指针位置

    if (currentPos == -1) {
      return -1;
    }
  }

  if (whence == std::ios_base::beg) {
    inputfile.seekg(offset, std::ios_base::beg);
    outputfile.seekp(offset, std::ios_base::beg);
  } else if (whence == std::ios_base::cur) {
    inputfile.seekg(offset, std::ios_base::cur);
    outputfile.seekp(offset, std::ios_base::cur);
  } else if (whence == std::ios_base::end) {
    inputfile.seekg(offset, std::ios_base::end);
    outputfile.seekp(offset, std::ios_base::end);
  }

  std::streampos newPos = inputfile.tellg(); // 返回读指针位置

  return newPos;
}
