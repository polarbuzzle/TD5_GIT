#ifndef BOUTON_H
#define BOUTON_H

#include<QToolButton>

class Bouton : public QToolButton
{
    Q_OBJECT
public:
    Bouton(const QString &text, QWidget *parent = 0);
    QSize sizeHint() const;
};

#endif // BOUTON_H
