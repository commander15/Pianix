#include "device.h"

Device::Device(const QString &name) :
    QSerialPort(name)
{
    connect(this, &QIODevice::readyRead, this, &Device::readNoteData);
}

void Device::readNoteData()
{
    m_buffer.append(readAll().trimmed());
    qDebug("%s", m_buffer.constData());

    if (m_buffer.size() >= 3)
        processNoteData();
}

void Device::processNoteData()
{
    while (!m_buffer.isEmpty() && !m_buffer.startsWith('*'))
        m_buffer.remove(0, 1);

    if (m_buffer.contains('#')) {
        QByteArray buffer = m_buffer.left(3).mid(1, 1);
        m_buffer.remove(0, 3);

        emit notePlayRequested(buffer.toInt());
    }
}
