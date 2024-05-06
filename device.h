#ifndef DEVICE_H
#define DEVICE_H

#include <QSerialPort>

class Device : public QSerialPort
{
    Q_OBJECT

public:
    Device(const QString &name);

    Q_SIGNAL void notePlayRequested(int note);

private:
    Q_SLOT void readNoteData();
    void processNoteData();

    QByteArray m_buffer;
};

#endif // DEVICE_H
