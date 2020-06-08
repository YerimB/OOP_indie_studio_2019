/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Image
*/

#include <Headers/Components/Image.h>
#include <iostream>

Image::Image(GuiEnvironment *GUIEnv)
{
    this->m_GUIEnvironment = GUIEnv;
}

bool Image::Initialize(void *args)
{
    this->m_Image = m_GUIEnvironment->addImage({0, 0, 0, 0});
    if (!this->m_Image)
        return (false);
    else if (args)
        this->SetTexture(static_cast<Texture *>(args));
    this->SetColor();
    return (true);
}

void Image::Update(const float &) {}

void Image::SetTexture(Texture *t)
{
    if (!t)
        return;
    this->m_Texture = t;
    this->m_Image->setImage(this->m_Texture);
    this->m_Image->setScaleImage(true);
}

void Image::SetColor(const Color &c)
{
    this->m_clr = c;
    this->m_Image->setColor(this->m_clr);
}

GuiImage *Image::GetImage(void)
{
    return (this->m_Image);
}

Texture *Image::GetTexture(void)
{
    return (this->m_Texture);
}

const Color &Image::GetColor(void)
{
    return this->m_clr;
}