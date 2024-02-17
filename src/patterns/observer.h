#ifndef S21_OBSERVER_H
#define S21_OBSERVER_H

#include <QObject>

namespace s21 {
class Observer {
 public:
  virtual void updateResult(const QString &message) = 0;

  virtual void updateError(const QString &error) = 0;
};
}  // namespace s21

#endif  // S21_OBSERVER_H
