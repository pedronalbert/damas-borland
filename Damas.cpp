//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("JuegoFormUnit.cpp", JuegoForm);
USEFORM("HomeFormUnit.cpp", HomeForm);
USEFORM("SelecJugadoresUnit.cpp", SelecJugadoresForm);
USEFORM("RecordsFormUnit.cpp", RecordsForm);
USEFORM("RegistrarUnit.cpp", RegistrarForm);
USEFORM("ConfiguracionUnit.cpp", ConfiguracionForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(THomeForm), &HomeForm);
                 Application->CreateForm(__classid(TSelecJugadoresForm), &SelecJugadoresForm);
                 Application->CreateForm(__classid(TJuegoForm), &JuegoForm);
                 Application->CreateForm(__classid(TRecordsForm), &RecordsForm);
                 Application->CreateForm(__classid(TRegistrarForm), &RegistrarForm);
                 Application->CreateForm(__classid(TConfiguracionForm), &ConfiguracionForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
