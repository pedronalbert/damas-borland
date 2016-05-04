//---------------------------------------------------------------------------

#ifndef SelecJugadoresUnitH
#define SelecJugadoresUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TSelecJugadoresForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TImage *Button1;
        TLabel *Label3;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TImage *RegistrarButton;
        TImage *Image2;
        TLabel *Label4;
        TImageList *AvatarList;
        TPaintBox *Avatar1;
        TPaintBox *Avatar2;
        TComboBox *ComboBox4;
        TComboBox *ComboBox5;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall RegistrarButtonClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall ComboBox4Change(TObject *Sender);
        void __fastcall ComboBox5Change(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSelecJugadoresForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSelecJugadoresForm *SelecJugadoresForm;
//---------------------------------------------------------------------------
#endif
