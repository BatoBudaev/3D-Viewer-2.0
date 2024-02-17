#ifndef CPP4_3DVIEWER_V2_0_1_SINGLETON_H
#define CPP4_3DVIEWER_V2_0_1_SINGLETON_H

#include <QString>

namespace s21 {
class FileManager {
 private:
  static FileManager *instance;
  std::string fileName;

 protected:
  FileManager() {}

  FileManager(const FileManager &other);

  FileManager(FileManager &&other);

  void operator=(const FileManager &other);

  ~FileManager() { delete instance; }

 public:
  static FileManager *getInstance();

  void setFileName(const std::string &name) { fileName = name; }

  std::string getFileName() const { return fileName; }
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SINGLETON_H
