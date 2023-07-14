#include "StoreWindow.h"
#include "ui_storewindow.h"
#include "variables/variables.h"

StoreWindow::StoreWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StoreWindow)
{
    ui->setupUi(this);
    Init();
    voice_store = new QSoundEffect;
    border_color_it = 0;
    choice_num = 4;
    target_pos = -1;
    choose_no = 0;
}

void StoreWindow::Init()
{
    this->setFocusPolicy(Qt::StrongFocus);

    ui->graphicsView_2->setStyleSheet("border:3px solid #FFFFFF;");
    ui->graphicsView_2->setFocusPolicy(Qt::NoFocus);

    ui->label->setFocusPolicy(Qt::NoFocus);
    ui->label_2->setFocusPolicy(Qt::NoFocus);
    ui->label_3->setFocusPolicy(Qt::NoFocus);
    ui->label_4->setFocusPolicy(Qt::NoFocus);
    ui->label_5->setFocusPolicy(Qt::NoFocus);
    ui->label_6->setFocusPolicy(Qt::NoFocus);

    BorderColorTimer = new QTimer();
    connect(BorderColorTimer, SIGNAL(timeout()), this, SLOT(OnColorTimerTriggered()));
    BorderColorTimer->start(100);
}

void StoreWindow::set_buy_atk_command(std::shared_ptr<Command> command)
{
    buy_atk_command = command;
}

void StoreWindow::set_buy_def_command(std::shared_ptr<Command> command)
{
    buy_def_command = command;
}

void StoreWindow::set_buy_hp_command(std::shared_ptr<Command> command)
{
    buy_hp_command = command;
}

void StoreWindow::OpenStore(GLOBAL_VARS* Vars)
{
    this->Vars = Vars;
    choose_no = 0;
    ui->graphicsView_2->setGeometry(32, 112, 192, 32);
}

void StoreWindow::OnColorTimerTriggered()
{
    if (border_color_it <= 4)
        border_color_it++;
    else
        border_color_it = 0;

    ui->graphicsView_2->setStyleSheet(QString::fromStdString("border:3px solid #") + QString::fromStdString(BorderColor[border_color_it]) + QString::fromStdString(";"));
}

void StoreWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){ //向上
        if (choose_no > 0)
        {
            voice_store->setSource(QUrl::fromLocalFile(":/music/store_.wav"));
            voice_store->setLoopCount(1);
            voice_store->setVolume(5.0f);
            voice_store->play();
            choose_no -= 1;
            ui->graphicsView_2->setGeometry(32, 112 + 48 * choose_no, 192, 32);
        }
        else
            choose_no = 0;
    }
    else if (event->key() == Qt::Key_Down){ //向下
        if (choose_no <= choice_num - 2)
        {
            voice_store->setSource(QUrl::fromLocalFile(":/music/store_.wav"));
            voice_store->setLoopCount(1);
            voice_store->setVolume(5.0f);
            voice_store->play();
            choose_no += 1;
            ui->graphicsView_2->setGeometry(32, 112 + 48 * choose_no, 192, 32);
        }
        else
            choose_no = choice_num - 1;
    }
    else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter || event->key() == Qt::Key_Space){
        handle_store(choose_no, target_pos);
    }
}
void StoreWindow::handle_store(int choice_no, int target_pos)
{
    // 商店处理
    if (choose_no != choice_num - 1){
        if (choice_no == 0)
        {
            buy_hp_command->exec();
        }
        else if (choice_no == 1)
        {
            buy_atk_command->exec();
        }
        else if (choice_no == 2)
        {
            buy_def_command->exec();
        }
    }
    else{
        Vars->OperationStatus = 0; //恢复主塔操作
        this->close();
        return;
    }
}

StoreWindow::~StoreWindow()
{
    delete ui;
}
