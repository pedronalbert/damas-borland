//---------------------------------------------------------------------------

#ifndef ConfiguracionUnitH
#define ConfiguracionUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TConfiguracionForm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TImage *Image2;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TComboBox *ComboBox1;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        TLabel *Label6;
        TCheckBox *CheckBox1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall ComboBox3Change(TObject *Sender);
        void __fastcall ComboBox4Change(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TConfiguracionForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfiguracionForm *ConfiguracionForm;
//---------------------------------------------------------------------------
#endif
