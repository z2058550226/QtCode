#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <GL/GLU.h>
#include <QTimer>
#include <QGLWidget>

class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

public slots:
    void updateAnimation();

private:
    QOpenGLContext *context;
    QOpenGLFunctions *openGLFunctions;
    float rotation;
    GLuint texID[1];
};

#endif // MAINWINDOW_H
