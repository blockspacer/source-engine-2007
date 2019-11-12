
#ifndef _MPxToolCommand
#define _MPxToolCommand
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MPxToolCommand
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MPxToolCommand)
//
// This is the base class for interactive tool commands.
//
// An interactive tool command is a command that can be invoked as a MEL command
// or from within a user defined context (see MPxContext).
//
// Tool commands have the same functionality as MPxCommands, but include several
// additional methods for use in interactive contexts:  cancel, finalize
// and doFinalize.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES



#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MPxCommand.h>

// *****************************************************************************

// DECLARATIONS

class MString;
class MFileObject;
class MArgList;

// *****************************************************************************

// CLASS DECLARATION (MPxToolCommand)

/// Base class for interactive tool commands (OpenMayaUI)
/**
  The base class for interactive tool commands
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MPxToolCommand : public MPxCommand
{
public:
	///
	MPxToolCommand(); // Called within a context

	///
	virtual ~MPxToolCommand();

	// The following are the methods for interactive use of a
    // MPxToolCommand object
	///
    virtual MStatus 	cancel();
	///
	virtual MStatus 	finalize();

protected:
	///
	MStatus				doFinalize( MArgList & command );

private:
// No private members
	virtual const char*	className() const;

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MPxToolCommand */

