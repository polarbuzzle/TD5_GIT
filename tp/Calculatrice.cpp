#include<QtGui>
#include<QGridLayout>
#include<math.h>

#include"Calculatrice.h"
#include"Erreur.h"

Calculatrice::Calculatrice(QWidget *parent): QWidget(parent)
{

    sumInMemory = 0.0;
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;
	//creation d'un objet de type QLineEdit avec par défaut la chaine de caractère 0
	//cette objet représente une zone de texte qui sera utilisé comme afficheur de la calculatrice
    display = new QLineEdit("0");
	
	// la zone de texte est paramétrée en lecture seule
    display->setReadOnly(true);
	
	// l'affichage se fera de la droite vers la gauche
    display->setAlignment(Qt::AlignRight);
	
	// définition de la largeur de la zone de texte à 15
    display->setMaxLength(15);

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);

    //MaFenetre  fenetre1;
    for(int i=0; i<NumDigitButtons; ++i)
    {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    Bouton *pointButton = createButton(tr("."), SLOT(pointClicked()));
    Bouton *changeSignButton = createButton(tr("\261"), SLOT(changeSignClicked()));

    Bouton *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    Bouton *clearButton = createButton(tr("Clear"), SLOT(clear()));
    Bouton *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));
	
	// Créez les boutons manquants ici
	//...
    Bouton *clearMemory = createButton(tr("MC"), SLOT(clearMemory()));
    Bouton *readMemory = createButton(tr("MR"), SLOT(readMemory()));
    Bouton *setMemory = createButton(tr("MS"), SLOT(setMemory()));
    Bouton *addToMemory = createButton(tr("M+"), SLOT(addToMemory()));

    Bouton *divisionButton = createButton(tr("/"), SLOT(multiplicativeOperatorClicked()));
    Bouton *timesButton = createButton(tr("X"), SLOT(multiplicativeOperatorClicked()));
    Bouton *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));
    Bouton *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    Bouton *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));
    Bouton *powerButton = createButton(tr("x\262"), SLOT(unaryOperatorClicked()));
    Bouton *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));
    Bouton *equalButton = createButton(tr("="), SLOT(equalClicked()));

		//Déclarez votre layout ici
		//...
        QGridLayout *mainLayout = new QGridLayout;

		//Gerer le positionnement des boutons sur le layout ici
		//...
        mainLayout->addWidget(display, 0, 0, 1, 6);
        mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);
        mainLayout->addWidget(clearButton, 1, 2, 1, 2);
        mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);
        mainLayout->addWidget(clearMemory, 2, 0);
        mainLayout->addWidget(digitButtons[7], 2, 1);
        mainLayout->addWidget(digitButtons[8], 2, 2);
        mainLayout->addWidget(digitButtons[9], 2, 3);
        mainLayout->addWidget(divisionButton, 2, 4);
        mainLayout->addWidget(squareRootButton, 2, 5);
        mainLayout->addWidget(readMemory, 3, 0);
        mainLayout->addWidget(digitButtons[4], 3, 1);
        mainLayout->addWidget(digitButtons[5], 3, 2);
        mainLayout->addWidget(digitButtons[6], 3, 3);
        mainLayout->addWidget(timesButton, 3, 4);
        mainLayout->addWidget(powerButton, 3, 5);
        mainLayout->addWidget(setMemory, 4, 0);
        mainLayout->addWidget(digitButtons[1], 4, 1);
        mainLayout->addWidget(digitButtons[2], 4, 2);
        mainLayout->addWidget(digitButtons[3], 4, 3);
        mainLayout->addWidget(minusButton, 4, 4);
        mainLayout->addWidget(reciprocalButton, 4, 5);
        mainLayout->addWidget(addToMemory, 5, 0);
        mainLayout->addWidget(digitButtons[0], 5, 1);
        mainLayout->addWidget(pointButton, 5, 2);
        mainLayout->addWidget(changeSignButton, 5, 3);
        mainLayout->addWidget(plusButton, 5, 4);
        mainLayout->addWidget(equalButton, 5, 5);
        // Ajout du layout à la fenetre principale
		// Ajout du layout à la fenetre principale
		setLayout(mainLayout);
		// Ajout du titre de la  fenetre
        setWindowTitle(tr("Calculatrice"));
}

void Calculatrice::digitClicked()
{
    Bouton *clickedButton = qobject_cast<Bouton* >(sender());
    int digitValue = clickedButton->text().toInt();
    if(display->text() =="0" && digitValue == 0.0)
        return;


    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));

}

void Calculatrice::unaryOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    if(clickedOperator == tr("Sqrt"))
    {
        try
        {
            if(operand < 0.0)
            {
                throw OperationInvalide("Exception racine carre negative impossible!");
                abortOperation();
                return;
            }
        result = sqrt(operand);
        }
        catch(OperationInvalide const& e)
        {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
    else if(clickedOperator == tr("x\262"))
    {
        result = pow(operand, 2.0);
    }
    else if(clickedOperator == tr("1/x"))
    {
        try
        {
            if(operand == 0.0)
            {
                throw OperationInvalide("Exception inverse de 0 impossible!");
                abortOperation();
                return;
            }
            result = 1.0 / operand;
        }
        catch(OperationInvalide const& e)
        {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
    display->setText(QString::number(result));
    waitingForOperand = true;
}

void Calculatrice::additiveOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    sumSoFar = operand;

    pendingAdditiveOperator = clickedOperator;

    waitingForOperand = true;
}

void Calculatrice:: multiplicativeOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    factorSoFar = operand;

    pendingMultiplicativeOperator = clickedOperator;

    waitingForOperand = true;
}

void Calculatrice::equalClicked()
{
    double operand = display->text().toDouble();

    if(!pendingMultiplicativeOperator.isEmpty())
    {
        if(!calculate(operand, pendingMultiplicativeOperator))
        {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if(!pendingAdditiveOperator.isEmpty())
    {
        if(!calculate(operand, pendingAdditiveOperator))
        {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    }
    else
    {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void Calculatrice::pointClicked()
{
    if(waitingForOperand)
    {
        display->setText("0");
    }
    if(!display->text().contains("."))
    {
        display->setText(display->text() + tr("."));
    }
    waitingForOperand = false;
}

void Calculatrice::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if(value > 0.0)
    {
        text.prepend(tr("-"));
    }
    else if(value < 0.0)
    {
        text.remove(0, 1);
    }
    display->setText(text);
}

void Calculatrice::backspaceClicked()
{
    if(waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1);
    if(text.isEmpty())
    {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}

void Calculatrice::clear()
{
    if(waitingForOperand)
        return;

    display->setText("0");
    waitingForOperand = true;
}

/********************************************************************************
 * Description      : Réinitialise toutes les valeurs et toutes les opérations
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/ 
void Calculatrice::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    display->setText("0");
    waitingForOperand = true;

}

void Calculatrice::clearMemory()
{
    sumInMemory = 0.0;
}

void Calculatrice::readMemory()
{
    display->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}

void Calculatrice::setMemory()
{
    equalClicked();
    sumInMemory = display->text().toDouble();
}

void Calculatrice::addToMemory()
{
    equalClicked();
    sumInMemory += display->text().toDouble();
}

Bouton *Calculatrice::createButton(const QString &text, const char *member)
{
    Bouton *button = new Bouton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Calculatrice::abortOperation()
{
    clearAll();
    return;
}

/*********************************************
*Fonctions:		calculate
*Descriptions:	calcule les opérations +, -, /, etc
*Parametre:		-(double)rightOperand		: L'operande de droite dans l'equation
				-(QString)pendingOperator	: Un string qui correspond a l'operation effectuee
*Retour:		-(bool)						: booleen qui confirme si l'operation a bien ete effectuee
*********************************************/
bool Calculatrice::calculate(double rightOperand, const QString &pendingOperator)
{
    if(pendingOperator == tr("+"))
    {
        sumSoFar +=rightOperand;
    }
    else if(pendingOperator == tr("-"))
    {
        sumSoFar -= rightOperand;
    }
    else if(pendingOperator == tr("X"))
    {
        factorSoFar *= rightOperand;
    }
    else if(pendingOperator == tr("/"))
    {
        try
        {
            if (rightOperand == 0.0)
            {
                abortOperation();
                throw OperationInvalide();

                return false;
            }
        factorSoFar /= rightOperand;
        }
        catch(OperationInvalide const& e)
        {
            QMessageBox::critical(this, "Error", e.what());
        }
    }
    return true;

}



