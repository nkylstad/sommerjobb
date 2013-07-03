#include <QtApplication>
#include <QVTKWidget>
#include <vtkJPEGReader>
#include <vtkImageViewer>

int main(int argc, char* argv[])
{

    QApplication *app = new QApplication;

    QVTKWidget *widget = new QVTKWidget;
    widget->resize(256,256);

    vtkJPEGReader *reader = vtkJPEGReader::New();
    reader->setFileName("butterfly.jpg");
    printSize(reader, 1);

    vtkImageViewer *viewer = vtkImageViewer::New();
    viewer->setInputConnection(reader->getOutputPort());
    viewer->setColorLevel(128);
    viewer->setColorWindow(256);

    vtkRenderWindow *renderWindow = viewer->getRenderWindow();
    widget->SetRenderWindow(renderWindow);
    // viewer->SetupInteractor(
    // renderWindow->GetInteractor());
    printSize(reader, 2);
    renderWindow->Render();
    printSize(reader, 3);
    int *size = imageSize(reader);
    widget->resize(size[0], size[1]);
    widget->show();
    app.exec();
    // Clean up
    viewer->Delete(); // VTK style
    reader->Delete();
    delete widget; // Qt / C++ style


}
