/**
 * @file mainwindow.h
 * @brief Заголовочный файл главного окна приложения с вкладками
 * @date 2025
 */

#pragma once

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QBuffer>
#include <QTabWidget>
#include <QLabel>
#include "apiclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Класс MainWindow представляет главное окно приложения с вкладками
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса MainWindow
     * @param parent Родительский виджет
     */
    explicit MainWindow(QWidget *parent = nullptr);
    
    /**
     * @brief Деструктор класса MainWindow
     */
    ~MainWindow();

private slots:
    /**
     * @brief Обработчик нажатия кнопки "Внедрить" для внедрения сообщения в изображение
     */
    void onEmbedMessageClicked();
    
    /**
     * @brief Обработчик нажатия кнопки "Извлечь" для извлечения сообщения из изображения
     */
    void onExtractMessageClicked();
    
    /**
     * @brief Обработчик нажатия кнопки "Выбрать изображение" для внедрения сообщения
     */
    void onSelectImageForEmbedClicked();
    
    /**
     * @brief Обработчик нажатия кнопки "Выбрать изображение" для извлечения сообщения
     */
    void onSelectImageForExtractClicked();
    
    /**
     * @brief Обработчик нажатия кнопки "Сохранить изображение" после внедрения сообщения
     */
    void onSaveImageClicked();
    
    /**
     * @brief Обработчик изменения вкладки
     * @param index Индекс выбранной вкладки
     */
    void onTabChanged(int index);

    // Новые слоты для вкладок
    void onEncryptAesClicked();
    void onDecryptAesClicked();
    void onHashSha384Clicked();
    void onSolveChordMethodClicked();
    void onClearChordMethodClicked();

    /**
     * @brief Обработчик ответа от API сервера
     * @param endpoint Конечная точка API
     * @param success Успешность операции
     * @param result Результат операции
     * @param error Описание ошибки (если есть)
     */
    void onApiResponse(const QString &endpoint, bool success, const QJsonObject &result, const QString &error);

private:
    /**
     * @brief Отображает изображение в метке
     * @param image Изображение для отображения
     */
    void displayImage(const QImage &image);
    
    /**
     * @brief Добавляет сообщение в текстовое поле вывода
     * @param message Сообщение для добавления
     */
    void appendToOutput(const QString &message);

private:
    Ui::MainWindow *ui; ///< Указатель на UI главного окна
    QImage m_originalImage; ///< Исходное изображение
    QImage m_stegoImage; ///< Изображение с внедренным сообщением
    QString m_lastImagePath; ///< Путь к последнему выбранному изображению
    QByteArray m_aesKey; // Ключ для AES
    QByteArray m_aesPlaintext; // Открытый текст для AES
    QByteArray m_aesCiphertext; // Зашифрованный текст для AES
};

