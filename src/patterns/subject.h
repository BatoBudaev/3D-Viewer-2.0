#ifndef S21_SUBJECT_H
#define S21_SUBJECT_H

#include <QObject>
#include <list>

#include "observer.h"

namespace s21 {
class Subject {
 private:
  std::list<Observer *> observers;

 public:
  void addObserver(Observer *observer) { observers.push_back(observer); }

  void removeObserver(Observer *observer) { observers.remove(observer); }

  void notifyObserversAboutResult(const QString &error) {
    for (Observer *observer : observers) {
      observer->updateResult(error);
    }
  }

  void notifyObserversAboutError(const QString &error) {
    for (Observer *observer : observers) {
      observer->updateError(error);
    }
  }
};
}  // namespace s21

#endif  // S21_SUBJECT_H
