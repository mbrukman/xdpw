// XD Pascal - a 32-bit compiler for Windows
// Developed by Vasiliy Tereshkov, 2009-2010, 2019

// Wrapper for Delphi build


{$APPTYPE CONSOLE}
{$ALIGN 1}
{$I-}



uses Windows;



const
  STRINGFIRSTINDEX = 1;



type
  TString  = string [80];
  TKeyName = string [80];
  
  TInFile = file;
  TOutFile = file;
  

  
function CustomStrComp(const s1, s2: TString): Integer;
begin
if s1 > s2 then
  Result := 1
else if s1 < s2 then
  Result := -1
else
  Result := 0;
end;




procedure CustomStrAppend(var s: TString; ch: Char);
begin
s := s + ch;
end;




procedure CustomChangeExt(const InStr, Ext: TString; var OutStr: TString);
var
  i, DotPos: Integer;
begin
i := Length(InStr);
DotPos := 0;

while (i > 0) and (DotPos = 0) do
  begin
  if InStr[i] = '.' then DotPos := i;
  Dec(i);
  end;

if DotPos > 0 then
  OutStr := Copy(InStr, 1, DotPos) + Ext
else
  OutStr := InStr + Ext;
end;




procedure CustomParamStr(Index: Integer; var Str: TString);
begin  
Str := ParamStr(Index);
end;




procedure CustomReset(var F: TInFile; const Name: TString);
begin
Assign(F, Name);
Reset(F, 1);
end;




procedure CustomRewrite(var F: TOutFile; const Name: TString);
begin
Assign(F, Name);
Rewrite(F, 1);
end;




procedure CustomBlockWrite(var F: TOutFile; Buf: Pointer; Len: Integer);
begin
BlockWrite(F, Buf^, Len);
end;




procedure CustomReadChar(var F: TInFile; var ch: Char);
var
  LenRead: Integer;
begin
BlockRead(F, ch, 1, LenRead);
if LenRead = 0 then ch := #0;
end;


 
  


