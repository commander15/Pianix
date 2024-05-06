#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>

#include <QMediaPlayer>

#include <QTimer>

#include "notes.h"

namespace Ui {
class NoteWidget;
}

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWidget(QWidget *parent = nullptr);
    ~NoteWidget();

    void setNote(int note);

    void setPlayer(QMediaPlayer *player);

    Q_SLOT void play();

private:
    Q_SLOT void updateSoundLevel();

    Ui::NoteWidget *ui;
    QMediaPlayer *player;
    QTimer timer;

    QString m_name;
    int m_note;
};

#endif // NOTEWIDGET_H
