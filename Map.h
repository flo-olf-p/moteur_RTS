#ifndef _MAP_H
#define _MAP_H

#include <QWidget>

class Map: public QWidget
{
public:
    Map(QWidget *parent = nullptr);
    virtual ~Map();

    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void paintEvent(QPaintEvent *event) override;

    void start();
};

#endif
