#include "notewidget.h"
#include "ui_notewidget.h"

NoteWidget::NoteWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NoteWidget)
    , m_note(DO)
{
    ui->setupUi(this);

    connect(ui->playButton, &QAbstractButton::clicked, this, &NoteWidget::play);

    timer.setInterval(5);
    connect(&timer, &QTimer::timeout, this, &NoteWidget::updateSoundLevel);
}

NoteWidget::~NoteWidget()
{
    delete ui;
}

void NoteWidget::setNote(int note)
{
    switch (note) {
    case DO:
        m_name = QStringLiteral("DO");
        break;

    case RE:
        m_name = QStringLiteral("RE");
        break;

    case MI:
        m_name = QStringLiteral("MI");
        break;

    case FA:
        m_name = QStringLiteral("FA");
        break;

    case SOL:
        m_name = QStringLiteral("SOL");
        break;

    case LA:
        m_name = QStringLiteral("LA");
        break;

    case CI:
        m_name = QStringLiteral("CI");
        break;

    default:
        m_name = QString();
        break;
    }

    ui->iconOutput->setText(m_name);
    ui->playButton->setText(m_name);

    m_note = note;
}

void NoteWidget::setPlayer(QMediaPlayer *player)
{
    this->player = player;
}

void NoteWidget::play()
{
    if (player->isPlaying())
        player->stop();

    QString key = "0" + QString::number(m_note);
    player->setSource(QUrl("qrc:/sounds/key" + key + ".mp3"));
    player->play();

    ui->soundOutput->setValue(0);
    timer.start();
}

void NoteWidget::updateSoundLevel()
{
    if (ui->soundOutput->value() < 100) {
        ui->soundOutput->setValue(ui->soundOutput->value() + 1);
    } else
        timer.stop();
}
