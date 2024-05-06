#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->doWidget->setNote(DO);
    ui->doWidget->setPlayer(&player);

    ui->reWidget->setNote(RE);
    ui->reWidget->setPlayer(&player);

    ui->miWidget->setNote(MI);
    ui->miWidget->setPlayer(&player);

    ui->faWidget->setNote(FA);
    ui->faWidget->setPlayer(&player);

    ui->solWidget->setNote(SOL);
    ui->solWidget->setPlayer(&player);

    ui->laWidget->setNote(LA);
    ui->laWidget->setPlayer(&player);

    ui->ciWidget->setNote(CI);
    ui->ciWidget->setPlayer(&player);

    player.setAudioOutput(new QAudioOutput(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playNote(int note)
{
    NoteWidget *w = noteWidget(note);
    w->play();
}

NoteWidget *MainWindow::noteWidget(int note) const
{
    switch (note) {
    case DO:
        return ui->doWidget;

    case RE:
        return ui->reWidget;

    case MI:
        return ui->miWidget;

    case FA:
        return ui->faWidget;

    case SOL:
        return ui->solWidget;

    case LA:
        return ui->laWidget;

    case CI:
        return ui->ciWidget;

    default:
        return nullptr;
    }
}
