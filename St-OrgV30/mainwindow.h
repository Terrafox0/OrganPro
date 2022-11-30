#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void ClearDate();
    void date_select();
    void on_save_button_clicked();
    void on_mount_textChanged(const QString &arg1);
    void on_year_textChanged(const QString &arg1);
};
#endif // MAINWINDOW_H
