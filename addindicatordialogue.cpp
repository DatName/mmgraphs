#include "addindicatordialogue.h"
#include "ui_addindicatordialogue.h"

AddIndicatorDialogue::AddIndicatorDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddIndicatorDialogue)
{
    ui->setupUi(this);
}

AddIndicatorDialogue::~AddIndicatorDialogue()
{
    delete ui;
}
