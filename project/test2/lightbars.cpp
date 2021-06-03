#include "lightbars.h"
#include <QDebug>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsScene>

lightbars::lightbars(const int& _pos_x):pos_x(_pos_x)
{
    qDebug()<<"lightbars borned"<<endl;
    bound_x = pos_x;
    bound_y = pos_y;
}

QRectF lightbars::boundingRect() const
{
    qreal adjust = 0.5;
//    return QRectF(-18 - adjust, -22 - adjust,
//                  36 + adjust, 60 + adjust);
    return  QRectF(bound_x,pos_y-22,bar_width,bar_height);

}

void lightbars::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

//    bound_x = pos_x;
//    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::green : Qt::red);

//    //left one
//    bound_x = pos_x-200;
//    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::green : Qt::yellow);



    bound_x = pos_x;
    if(scene()->collidingItems(this).size()>=3){
        painter->setBrush(Qt::red);
    }else{
        bound_x = pos_x+200;
        if(scene()->collidingItems(this).size()>=2){
            painter->setBrush(Qt::yellow);
        }else{
            painter->setBrush(Qt::green);
        }
    }


    //大胆的想法，用不同的bounding rect替代不同长度的空闲区间是否有车，通过与本对象的绝对位置来判断有几个空闲区间
//    if(scene()->collidingItems(this).isEmpty()){
//        if(state == ONE_FREE){
//            painter->setBrush(Qt::yellow);
//        }else {
//            painter->setBrush(Qt::green);
//        }
//    }else{
//        painter->setBrush(Qt::red);
//        //emit
//        emit lbChange(ONE_FREE);

//    }
    painter->drawRect(pos_x,pos_y,bar_width-2,bar_height);

//    //bouding rect
//    painter->setPen(QPen(Qt::white,1,Qt::DotLine,Qt::SquareCap,Qt::MiterJoin));
//    painter->drawRect(bound_x,pos_y+25,bar_width,bar_height);
}

//void lightbars::lbSet(int _state){
//    this->state = _state;
//    qDebug()<<"change state"<<endl;
//}

