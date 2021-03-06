Imports EnvDTE
Imports System.Diagnostics

'
' This module contains macros that only work in vs2005 or later.
'
Public Module Valve2005
    Class ClipboardCopier
        Sub DoCopy()
            Dim t As System.Threading.Thread = New System.Threading.Thread(AddressOf MyThreadFunction)
            t.SetApartmentState(System.Threading.ApartmentState.STA)
            t.Start()
            t.Join()    ' Wait for the thread to finish.
        End Sub

        Sub MyThreadFunction()
            Dim x As String
            x = System.Windows.Forms.Clipboard.GetText()
            System.Windows.Forms.Clipboard.SetText(x)
        End Sub
    End Class

    Sub CopyToClipboardAsPlainText()
        ' First have the app copy stuff to the clipboard.
        DTE.ExecuteCommand("Edit.Copy")

        ' Now convert the clipboard contents to plain text.
        ' Must do this inside a thread with a state that .net likes.
        Dim cc As New ClipboardCopier
        cc.DoCopy()
    End Sub
End Module
