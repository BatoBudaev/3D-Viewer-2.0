#ifndef CPP4_3DVIEWER_V2_0_1_ICOMMAND_H
#define CPP4_3DVIEWER_V2_0_1_ICOMMAND_H

namespace s21 {
class ICommand {
 public:
  virtual ~ICommand() = default;

  virtual void execute() = 0;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_ICOMMAND_H
