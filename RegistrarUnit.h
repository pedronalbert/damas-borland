//---------------------------------------------------------------------------

#ifndef RegistrarUnitH
#define RegistrarUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TRegistrarForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TImage *RegistrarButton;
        TImage *Image2;
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall RegistrarButtonClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
        void TRegistrarForm::limpiarEdits();
public:		// User declarations
        __fastcall TRegistrarForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRegistrarForm *RegistrarForm;
//---------------------------------------------------------------------------
#endif
