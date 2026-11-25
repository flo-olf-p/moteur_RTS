#include "QtWidgetsDebugMenu.h"
#include <iostream>
#include <qdebug.h>

QtWidgetsDebugMenu::QtWidgetsDebugMenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.Update, &QPushButton::clicked, this, [this]()
		{
			int newSize = ui.SizeCase->value();

			emit gridSizeChanged(newSize);
		});

	connect(ui.AddAnimal, &QPushButton::clicked, this, [this]()
		{
			int PredNumber = ui.PredNumber->value();
			int HerbNumber = ui.HerbNumber->value();


			emit addAnimalButton(PredNumber, HerbNumber);
		});
	connect(ui.EndTurn, &QPushButton::clicked, this, [this]()
		{
			emit endTurn();
		});
}

QtWidgetsDebugMenu::~QtWidgetsDebugMenu()
{}

