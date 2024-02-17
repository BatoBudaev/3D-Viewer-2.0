#include "singleton.h"

namespace s21 {
FileManager *FileManager::instance = nullptr;

FileManager *FileManager::getInstance() {
  if (!instance) {
    instance = new FileManager();
  }

  return instance;
}
}  // namespace s21
