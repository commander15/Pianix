#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class NoteWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Q_SLOT void playNote(int note);

private:
    NoteWidget *noteWidget(int note) const;

    Ui::MainWindow *ui;
    QMediaPlayer player;
};

#endif // MAINWINDOW_H
