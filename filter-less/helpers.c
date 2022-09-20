#include "helpers.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imageGray[height][width];
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int pixel_b = image[i][j].rgbtBlue;
            int pixel_r = image[i][j].rgbtGreen;
            int pixel_g = image[i][j].rgbtRed;
            float avarage = (pixel_b + pixel_r + pixel_g)/3.0;
            int avarage_int = lround(avarage);
            image[i][j].rgbtBlue = avarage_int;
            image[i][j].rgbtGreen = avarage_int;
            image[i][j].rgbtRed = avarage_int;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Valores originais e devidos calculos para o filtro
            float originalBlue= image[i][j].rgbtBlue;
            float originalGreen = image[i][j].rgbtGreen;
            float originalRed = image[i][j].rgbtRed;
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            //verificação de limite máximo
            if (sepiaRed > 255){
                sepiaRed = 255.0;
            }
            if (sepiaGreen > 255.0){
                sepiaGreen = 255.0;
            }
            if (sepiaBlue > 255){
                sepiaBlue = 255.0;
            }

            //Conversão para inteiro e nova imagem
            int sepiaRedPixel = lround(sepiaRed);
            int sepiaGreenPixel = lround(sepiaGreen);
            int sepiaBluePixel = lround(sepiaBlue);
            image[i][j].rgbtBlue = sepiaBluePixel;
            image[i][j].rgbtGreen = sepiaGreenPixel;
            image[i][j].rgbtRed = sepiaRedPixel;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int reference;
    if (width % 2 == 0)
    {
        reference = width/2;
    }
    else {
        reference = (width + 1)/2;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < reference; j++)
        {
            //Pixel da direita
            RGBTRIPLE *pixelL = &image[i][j];
            RGBTRIPLE *pixelR = &image[i][width - 1 - j];

            // Variable Temporable
            RGBTRIPLE tmp = *pixelR;

            // swap
            image[i][width - 1 - j]= *pixelL;
            image[i][j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Image Copy
    RGBTRIPLE imageBlur[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imageBlur[i][j].rgbtBlue = image[i][j].rgbtBlue;
            imageBlur[i][j].rgbtGreen = image[i][j].rgbtGreen;
            imageBlur[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }
    // Operação
    // soma dos pixels vizinhos
    int sumBlue = 0;
    int sumGreen = 0;
    int sumRed = 0;
    float auxBlue = 0;
    float auxGreen = 0;
    float auxRed = 0;
    for  (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Elemento
            sumBlue += image[i][j].rgbtBlue;
            sumGreen += image[i][j].rgbtGreen;
            sumRed += image[i][j].rgbtRed;
            auxBlue += 1.0;
            auxGreen += 1.0;
            auxRed += 1.0;
            // Mesma linha
            if (j + 1 < width){
                sumBlue += image[i][j+1].rgbtBlue;
                sumGreen += image[i][j+1].rgbtGreen;
                sumRed += image[i][j+1].rgbtRed;
                auxBlue += 1.0;
                auxGreen += 1.0;
                auxRed += 1.0;
            }
            if (j - 1 >= 0){
                sumBlue += image[i][j-1].rgbtBlue;
                sumGreen += image[i][j-1].rgbtGreen;
                sumRed += image[i][j-1].rgbtRed;
                auxBlue += 1.0;
                auxGreen += 1.0;
                auxRed += 1.0;
            }
            // Top line
            if (i - 1 >= 0){
                sumBlue += image[i-1][j].rgbtBlue;
                sumGreen += image[i-1][j].rgbtGreen;
                sumRed += image[i-1][j].rgbtRed;
                auxBlue += 1.0;
                auxGreen += 1.0;
                auxRed += 1.0;
            }
            if (i - 1 >= 0 && j - 1 >= 0){
                sumBlue += image[i-1][j-1].rgbtBlue;
                sumGreen += image[i-1][j-1].rgbtGreen;
                sumRed += image[i-1][j-1].rgbtRed;
                auxBlue += 1.0;
                auxGreen += 1.0;
                auxRed += 1.0;
            }
            if (i - 1 >= 0 && j + 1 < width){
                sumBlue += image[i-1][j+1].rgbtBlue;
                sumGreen += image[i-1][j+1].rgbtGreen;
                sumRed += image[i-1][j+1].rgbtRed;
                auxBlue += 1.0;
                auxGreen += 1.0;
                auxRed += 1.0;
            }
            // Botton line
            if (i + 1 < height){
                sumBlue += image[i+1][j].rgbtBlue;
                sumGreen += image[i+1][j].rgbtGreen;
                sumRed += image[i+1][j].rgbtRed;
                auxBlue += 1.0;
                auxGreen += 1.0;
                auxRed += 1.0;
            }
            if (i + 1 < height && j - 1 >= 0){
                sumBlue += image[i+1][j-1].rgbtBlue;
                sumGreen += image[i+1][j-1].rgbtGreen;
                sumRed += image[i+1][j-1].rgbtRed;
                auxBlue += 1.0;
                auxGreen += 1.0;
                auxRed += 1.0;
            }
            if (i + 1 < height && j + 1 < width){
                sumBlue += image[i+1][j+1].rgbtBlue;
                sumGreen += image[i+1][j+1].rgbtGreen;
                sumRed += image[i+1][j+1].rgbtRed;
                auxBlue += 1.0;
                auxGreen += 1.0;
                auxRed += 1.0;
            }
            // Média para o pixel dado
            float AvarageBlue = sumBlue/auxBlue;
            float AvarageGreen = sumGreen/auxGreen;
            float AvarageRed = sumRed/auxRed;

            // inserção na image blur
            imageBlur[i][j].rgbtBlue = lround(AvarageBlue);
            imageBlur[i][j].rgbtGreen = lround(AvarageGreen);
            imageBlur[i][j].rgbtRed = lround(AvarageRed);

            // clean auxs
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            auxBlue = 0;
            auxGreen = 0;
            auxRed = 0;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = imageBlur[i][j].rgbtBlue;
            image[i][j].rgbtGreen = imageBlur[i][j].rgbtGreen;
            image[i][j].rgbtRed = imageBlur[i][j].rgbtRed;
        }
    }
    return;
}
