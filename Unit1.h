//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TChart *Chart1;
        TEdit *Edit1;
        TPanel *Panel1;
        TButton *Button4;
        TLabel *Label1;
        TButton *Button5;
        TStringGrid *StringGrid1;
        TButton *Button8;
        TPanel *Panel3;
        TEdit *Edit2;
        TButton *Button10;
        TLabel *Label3;
        TBarSeries *Series1;
        TMainMenu *MainMenu1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMemo *Memo1;
        void __fastcall StringGrid1KeyPress(TObject *Sender, char &Key);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
