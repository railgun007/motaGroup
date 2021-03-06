/*
 * File: communication.h
 * ---------------------
 * This file exports a class <code>communication</code>. Users are allow to
 * use <code>Key_Space</code> to continue communication or use Mouse to click
 * to choose conversation content, which is mainly part of multiple storylines.
 */

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QKeyEvent>
#include <QQueue>
#include <QObject>
#include "npc.h"
#include "Button.h"

class communication: public QObject, public QGraphicsRectItem
{   Q_OBJECT
public:
    // constructor
    communication(NPC* npc, QGraphicsItem* parent=nullptr);

    // public methods
    void keyPressEvent(QKeyEvent* event);
    bool checkOption(QString sentence);
    void showButton101();   // show button when communicate with NPC(id=101)
public slots:
    void addText10101();    // add different content
    void addText10102();
    void addText10103();

private:
    // private variable
    int id;
    QQueue<QString> communicationText;

    QGraphicsTextItem* text;
    Button* buttonOption1,* buttonOption2,* buttonOption3;
};

#endif // COMMUNICATION_H
