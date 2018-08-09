#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2,1);
    setFormat(format);

    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);

    openGLFunctions = context->functions();

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateAnimation()));
    timer->start(30);

    rotation = 0;
}

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL(){
    //Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);

    // Enable Texturing
    glEnable(GL_TEXTURE_2D);

    //QImage image("qrc:/image/bricks.jpg");
    //    QImage
//    QImage image;
//    image.fill(Qt::blue);
    QImage texture = QGLWidget::convertToGLFormat(image);

    glGenTextures(1, &texID[0]);
    glBindTexture(GL_TEXTURE_2D, texID[0]);

    // Point sampling of nearest neightbour
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,128, 128, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.bits());

    // Make sure render at correct aspect ratios
    resizeGL(this->width(),this->height());
}

void MainWindow::resizeGL(int w, int h){
    //Set the viewport
    glViewport(0,0,w,h);
    qreal aspectRatio = qreal(w)/qreal(h);

    //Initialize projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1*aspectRatio,-1*aspectRatio,-1,1,1,-1);
    //参数含义：1 指定视景体的视野角度，y轴上下方向
    gluPerspective(75,aspectRatio,0.1,400000000);

    //Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MainWindow::paintGL(){
    //Initialize clear color (cornflower blue)
    glClearColor(0.39f,0.58f,0.93f,1.f);


    //Clear color buffer
    //    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //Reset modelview matrix
    glMatrixMode(GL_MODELVIEW);
    //将当前矩阵乘以单位矩阵，否则x,y,z值将会在每次重绘时都进行改变
    glLoadIdentity();

    //Transformations
    glTranslatef(0.0,0.0,-3.0);
    glRotatef(rotation,1.0,1.0,1.0);

    // Texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID[0]);

    glEnable(GL_LIGHTING);

    // FRONT
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    // BACK
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f,-1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    // RIGHT
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, -0.5, 0.5);
    glEnd();

    // LEFT
    glBegin(GL_POLYGON);
    glNormal3f(0.0f,-1.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    // TOP
    glBegin(GL_POLYGON);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(-0.5, 0.5, 0.5);
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    //    glDisable(GL_LIGHTING);

    // Disable texturing once you're done
    glDisable(GL_TEXTURE_2D);
    glFlush();
}

void MainWindow::paintEvent(QPaintEvent *event){
    paintGL();
}

void MainWindow::resizeEvent(QResizeEvent *event){
    resizeGL(this->width(),this->height());
    this->update();
}

void MainWindow::updateAnimation(){
    rotation+=3;
    this->update();
}
