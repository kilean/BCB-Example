//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    //�s�u
    ClientSocket1->Host=Edit1->Text;
    ClientSocket1->Port=atoi(Edit2->Text.c_str());
    ClientSocket1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    //���u
    ClientSocket1->Socket->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    //�ǰe�T��
    ClientSocket1->Socket->SendText(Edit3->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
    if(ErrorCode==10061)
    {
        Memo1->Lines->Add("���A�����}��");
        ErrorCode=0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //��ܰT��
    Memo1->Lines->Add(Socket->ReceiveText());
}
//---------------------------------------------------------------------------

