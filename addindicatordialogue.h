#ifndef ADDINDICATORDIALOGUE_H
#define ADDINDICATORDIALOGUE_H

#include <QDialog>

namespace Ui {
class AddIndicatorDialogue;
}

class AddIndicatorDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit AddIndicatorDialogue(QWidget *parent = nullptr);
    ~AddIndicatorDialogue();

private:
    Ui::AddIndicatorDialogue *ui;
};

#endif // ADDINDICATORDIALOGUE_H
