//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HomeFormUnit.h"
#include "SelecJugadoresUnit.h"
#include "RecordsFormUnit.h"
#include "ConfiguracionUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THomeForm *HomeForm;

//---------------------------------------------------------------------------
__fastcall THomeForm::THomeForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THomeForm::NuevoJuegoButtonClick(TObject *Sender)
{
  SelecJugadoresForm->Show();
  HomeForm->Hide();        
}
//---------------------------------------------------------------------------
void __fastcall THomeForm::Image2Click(TObject *Sender)
{
  HomeForm->Close();        
}
//---------------------------------------------------------------------------
void __fastcall THomeForm::Image3Click(TObject *Sender)
{
  RecordsForm->Show();
  HomeForm->Hide();
}
//---------------------------------------------------------------------------
void __fastcall THomeForm::FormCreate(TObject *Sender)
{
  this->nJugadores = 0;
  this->idImagenCelda1 = 0;
  this->idImagenCelda2 = 2;
  this->idImagenFicha1 = 0;
  this->idImagenFicha2 = 1;
  this->reproducirMusica();
}
//---------------------------------------------------------------------------
void __fastcall THomeForm::Image4Click(TObject *Sender)
{
  ConfiguracionForm->Show();
  HomeForm->Hide();        
}

void THomeForm::mostrarCreditos() {
  ShowMessage("Luigi Antonio Raimundo Chacón CI: 25.837.345\nEdgar Daniel Gómez Sánchez CI: 21.219.570");
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::Creditos1Click(TObject *Sender)
{
  this->mostrarCreditos();        
}

void THomeForm::detenerMusica() {
  MediaPlayer1->Pause();
}

void THomeForm::reproducirMusica() {
  MediaPlayer1->Play();
}
//---------------------------------------------------------------------------



