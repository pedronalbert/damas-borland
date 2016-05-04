//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConfiguracionUnit.h"
#include "HomeFormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfiguracionForm *ConfiguracionForm;
//---------------------------------------------------------------------------
__fastcall TConfiguracionForm::TConfiguracionForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TConfiguracionForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  HomeForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TConfiguracionForm::Image2Click(TObject *Sender)
{
  HomeForm->Show();
  ConfiguracionForm->Hide();        
}
//---------------------------------------------------------------------------
void __fastcall TConfiguracionForm::ComboBox1Change(TObject *Sender)
{
  int id = ComboBox1->ItemIndex;

  if (id >= 0) {
    HomeForm->idImagenFicha1 = id;
  }
}
//---------------------------------------------------------------------------
void __fastcall TConfiguracionForm::ComboBox2Change(TObject *Sender)
{
  int id = ComboBox2->ItemIndex;

  if (id >= 0) {
    HomeForm->idImagenFicha2 = id;
  }
}
//---------------------------------------------------------------------------
void __fastcall TConfiguracionForm::ComboBox3Change(TObject *Sender)
{
  int id = ComboBox3->ItemIndex;

  if (id >= 0) {
    HomeForm->idImagenCelda1 = id;
  }
}
//---------------------------------------------------------------------------
void __fastcall TConfiguracionForm::ComboBox4Change(TObject *Sender)
{
  int id = ComboBox4->ItemIndex;

  if (id >= 0) {
    HomeForm->idImagenCelda2 = id;
  }
}
//---------------------------------------------------------------------------
void __fastcall TConfiguracionForm::FormShow(TObject *Sender)
{
  ComboBox1->ItemIndex = HomeForm->idImagenFicha1;
  ComboBox2->ItemIndex = HomeForm->idImagenFicha2;
  ComboBox3->ItemIndex = HomeForm->idImagenCelda1;
  ComboBox4->ItemIndex = HomeForm->idImagenCelda2;
}
//---------------------------------------------------------------------------

void __fastcall TConfiguracionForm::CheckBox1Click(TObject *Sender)
{
  if(CheckBox1->Checked) {
    HomeForm->reproducirMusica();
  } else {
    HomeForm->detenerMusica();
  }
}
//---------------------------------------------------------------------------

