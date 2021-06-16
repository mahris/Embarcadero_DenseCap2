unit DelphiTestForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls,
  System.ImageList, Vcl.ImgList;

type
  TDelphiTestFrm = class(TForm)
    Panel1: TPanel;
    Results: TMemo;
    edFile: TButtonedEdit;
    FileImages: TImageList;
    edkey: TLabeledEdit;
    edUrl: TLabeledEdit;
    Label1: TLabel;
    OpenDialog1: TOpenDialog;
    bnFile: TButton;
    bnUrl: TButton;
    procedure edFileRightButtonClick(Sender: TObject);
    procedure bnFileClick(Sender: TObject);
    procedure bnUrlClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  DelphiTestFrm: TDelphiTestFrm;

implementation

uses ActiveX;

{$R *.dfm}

function Densecap_ProcessFile(key, filename: TBSTR): TBSTR; cdecl; external 'DeepAIClrWrapper' name 'Densecap_ProcessFile';
function Densecap_ProcessUrl(key, filename: TBSTR): TBSTR; cdecl; external 'DeepAIClrWrapper' name 'Densecap_ProcessUrl';

procedure TDelphiTestFrm.bnFileClick(Sender: TObject);
var
  bkey, bfilename, bresult: TBSTR;
  skey,sfilename:string;
begin
  skey:=edKey.Text;
  bkey:=SysAllocString(pchar(skey));
  sfilename:=edFile.Text;
  bfilename:=SysAllocString(pchar(sfilename));
  Screen.Cursor := crHourGlass;
  try
    try
      bresult := Densecap_ProcessFile(bkey, bfilename);
    except
      on e: Exception do begin
        results.Lines.Add(e.Message);
        ShowMessage(e.Message);
        exit;
      end;
    end;
    Results.Text := bresult;
  finally
    Screen.Cursor := crDefault;
    if assigned(bkey) then SysFreeString(bkey);
    if assigned(bfilename) then SysFreeString(bfilename);
    if assigned(bresult) then SysFreeString(bresult);
  end;
end;

procedure TDelphiTestFrm.bnUrlClick(Sender: TObject);
var
  bkey, burl, bresult: TBSTR;
  skey,surl:string;
begin
  skey:=edKey.Text;
  bkey:=SysAllocString(pchar(skey));
  surl:=edUrl.Text;
  burl:=SysAllocString(pchar(surl));
  Screen.Cursor := crHourGlass;
  try
    try
      bresult := Densecap_ProcessUrl(bkey, burl);
    except
      on e: Exception do begin
        results.Lines.Add(e.Message);
        ShowMessage(e.Message);
        exit;
      end;
    end;
    Results.Text := bresult;
  finally
    Screen.Cursor := crDefault;
    if assigned(bkey) then SysFreeString(bkey);
    if assigned(burl) then SysFreeString(burl);
    if assigned(bresult) then SysFreeString(bresult);
  end;
end;

procedure TDelphiTestFrm.edFileRightButtonClick(Sender: TObject);
begin
  if OpenDialog1.Execute then
    edFile.Text := OpenDialog1.FileName;
end;

end.
