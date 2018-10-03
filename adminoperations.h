#ifndef ADMINOPERATIONS_H
#define ADMINOPERATIONS_H

#include <QDialog>

namespace Ui {
class AdminOperations;
}

class AdminOperations : public QDialog
{
    Q_OBJECT

public:
    explicit AdminOperations(QWidget *parent = nullptr);
    ~AdminOperations();




    private slots:
        void on_loginButton_clicked();

private:
    Ui::AdminOperations *ui;
};

#endif // ADMINOPERATIONS_H
