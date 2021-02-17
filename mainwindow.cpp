#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->flagsTable->horizontalHeader()->setStretchLastSection(true);
    ui->flagsTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->sourcesTable->horizontalHeader()->setStretchLastSection(true);
    ui->sourcesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->tabWidget, SIGNAL(currentChanged(int)),this, SLOT(currentTabChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InsertFlagItem(const QString & key, const QString & value)
{
    int row = ui->flagsTable->rowCount();
    ui->flagsTable->insertRow(row);

    auto keyColumn = new QTableWidgetItem(key);
    auto valueColumn = new QTableWidgetItem(value);

    ui->flagsTable->setItem(row,0,keyColumn);
    ui->flagsTable->setItem(row,1,valueColumn);
}

void MainWindow::InsertNewIncludeDirectory(const QString & dir)
{
    QListWidgetItem* newItem = new QListWidgetItem(dir);
    newItem->setFlags(newItem->flags()|Qt::ItemIsEditable);

    ui->includeList->addItem(newItem);
}

void MainWindow::addSource(const QString & target, const QString& sources)
{
    int row = ui->sourcesTable->rowCount();
    ui->sourcesTable->insertRow(row);

    auto targetColumn = new QTableWidgetItem(target);
    auto sourcesColumn = new QTableWidgetItem(sources);

    ui->sourcesTable->setItem(row, 0 , targetColumn);
    ui->sourcesTable->setItem(row, 1 , sourcesColumn);
}

void MainWindow::on_actionExport_triggered()
{
    QString projectName = ui->projectNameEdit->text();
}

void MainWindow::on_flagsAddBtn_clicked()
{
    InsertFlagItem("<Key>","<Value>");
}

void MainWindow::on_flagsRemoveBtn_clicked()
{
    ui->flagsTable->removeRow(ui->flagsTable->currentRow());
}

void MainWindow::on_addincludeBtn_clicked()
{
    InsertNewIncludeDirectory("<Path>");
}

void MainWindow::on_includeList_itemChanged(QListWidgetItem *item)
{
    if(item->text().length() == 0){
        ui->includeList->takeItem(ui->includeList->row(item));
    }
}

void MainWindow::on_addSourceBtn_clicked()
{
    addSource("<Target>", "main.cpp");

}

void MainWindow::on_removeSourceBtn_clicked()
{
    ui->sourcesTable->removeRow(ui->sourcesTable->currentRow());

}

void MainWindow::currentTabChanged(int index)
{
    //qDebug()<<"Current tab index "<<index<<endl;

    if(index == 4){
        ui->previewEdit->tex
    }
    else if(index == 3){

    }
    else if(index == 2){

    }
    else if(index == 1){

    }
    else if(index == 0){

    }
}
