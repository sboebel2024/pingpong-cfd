/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019-2021 OpenCFD Ltd.
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "fixedValueFvPatchFieldTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
#include "PatchFunction1.H"

//{{{ begin codeInclude

//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 940fdfb388c668e9ca5dc05d775674bb0aee2fa0
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void rotatingBC_940fdfb388c668e9ca5dc05d775674bb0aee2fa0(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

makeRemovablePatchTypeField
(
    fvPatchVectorField,
    rotatingBCFixedValueFvPatchVectorField
);

} // End namespace Foam


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::
rotatingBCFixedValueFvPatchVectorField::
rotatingBCFixedValueFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF
)
:
    parent_bctype(p, iF)
{
    if (false)
    {
        printMessage("Construct rotatingBC : patch/DimensionedField");
    }
}


Foam::
rotatingBCFixedValueFvPatchVectorField::
rotatingBCFixedValueFvPatchVectorField
(
    const rotatingBCFixedValueFvPatchVectorField& rhs,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    parent_bctype(rhs, p, iF, mapper)
{
    if (false)
    {
        printMessage("Construct rotatingBC : patch/DimensionedField/mapper");
    }
}


Foam::
rotatingBCFixedValueFvPatchVectorField::
rotatingBCFixedValueFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    parent_bctype(p, iF, dict)
{
    if (false)
    {
        printMessage("Construct rotatingBC : patch/dictionary");
    }
}


Foam::
rotatingBCFixedValueFvPatchVectorField::
rotatingBCFixedValueFvPatchVectorField
(
    const rotatingBCFixedValueFvPatchVectorField& rhs
)
:
    parent_bctype(rhs),
    dictionaryContent(rhs)
{
    if (false)
    {
        printMessage("Copy construct rotatingBC");
    }
}


Foam::
rotatingBCFixedValueFvPatchVectorField::
rotatingBCFixedValueFvPatchVectorField
(
    const rotatingBCFixedValueFvPatchVectorField& rhs,
    const DimensionedField<vector, volMesh>& iF
)
:
    parent_bctype(rhs, iF)
{
    if (false)
    {
        printMessage("Construct rotatingBC : copy/DimensionedField");
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::
rotatingBCFixedValueFvPatchVectorField::
~rotatingBCFixedValueFvPatchVectorField()
{
    if (false)
    {
        printMessage("Destroy rotatingBC");
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void
Foam::
rotatingBCFixedValueFvPatchVectorField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        printMessage("updateCoeffs rotatingBC");
    }

//{{{ begin code
    #line 55 "/home/sdatnmdt/cfd/pingpong/0/U/boundaryField/sphere"
const vector omega(0, 1, 0);
            const vector origin(0, 0, 0);

            const vectorField& centres = patch().Cf();  // Correct method

            forAll(centres, faceI)
            {
                operator[](faceI) = omega ^ (centres[faceI] - origin);
            }
//}}} end code

    this->parent_bctype::updateCoeffs();
}


// ************************************************************************* //

