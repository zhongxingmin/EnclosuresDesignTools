#ifdef _WIN64
#include "..\..\inc-x64\gcax_i.h"
#else
#include "..\..\inc-x86\gcax_i.h"
#endif
#include "acad2grx.h"
#define IAcadObjectEvents        IGcadObjectEvents
#define IAcadAcCmColor        IGcadAcCmColor
#define IAcadHyperlink        IGcadHyperlink
#define IAcadHyperlinks        IGcadHyperlinks
#define IAcadSectionTypeSettings        IGcadSectionTypeSettings
#define IAcadDatabasePreferences        IGcadDatabasePreferences
#define IAcadFileDependency        IGcadFileDependency
#define IAcadFileDependencies        IGcadFileDependencies
#define IAcadSummaryInfo        IGcadSummaryInfo
#define IAcaddApplicationEvents        _DGcadApplicationEvents
#define IAcadUtility        IGcadUtility
#define IAcaddDocumentEvents        _DGcadDocumentEvents
#define IAcadDynamicBlockReferenceProperty        IGcadDynamicBlockReferenceProperty
#define IAcadUseType        IGcadUseType
#define IAcadSecurityParams        IGcadSecurityParams
#define IAcaddScriptJetEvents        _IGcadScriptJetEvents
#define IAcadScriptJet        IGcadScriptJet
#define IAcadObject        IGcadObject
#define IAcadEntity        IGcadEntity
#define IAcad3DFace        IGcad3DFace
#define IAcadPolygonMesh        IGcadPolygonMesh
#define IAcad3DPolyline        IGcad3DPolyline
#define IAcadArc        IGcadArc
#define IAcadAttribute        IGcadAttribute
#define IAcadRegion        IGcadRegion
#define IAcad3DSolid        IGcad3DSolid
#define IAcadCircle        IGcadCircle
#define IAcadDimension        IGcadDimension
#define IAcadDimAligned        IGcadDimAligned
#define IAcadDimAngular        IGcadDimAngular
#define IAcadDimDiametric        IGcadDimDiametric
#define IAcadDimRotated        IGcadDimRotated
#define IAcadDimOrdinate        IGcadDimOrdinate
#define IAcadDimRadial        IGcadDimRadial
#define IAcadEllipse        IGcadEllipse
#define IAcadLeader        IGcadLeader
#define IAcadMText        IGcadMText
#define IAcadPoint        IGcadPoint
#define IAcadLWPolyline        IGcadLWPolyline
#define IAcadPolyline        IGcadPolyline
#define IAcadRay        IGcadRay
#define IAcadShape        IGcadShape
#define IAcadSolid        IGcadSolid
#define IAcadSpline        IGcadSpline
#define IAcadText        IGcadText
#define IAcadTolerance        IGcadTolerance
#define IAcadTrace        IGcadTrace
#define IAcadXline        IGcadXline
#define IAcadBlockReference        IGcadBlockReference
#define IAcadHatch        IGcadHatch
#define IAcadRasterImage        IGcadRasterImage
#define IAcadLine        IGcadLine
#define IAcadPlotConfiguration        IGcadPlotConfiguration
#define IAcadMInsertBlock        IGcadMInsertBlock
#define IAcadPolyfaceMesh        IGcadPolyfaceMesh
#define IAcadMLine        IGcadMLine
#define IAcadDim3PointAngular        IGcadDim3PointAngular
#define IAcadExternalReference        IGcadExternalReference
#define IAcadTable        IGcadTable
#define IAcadDimArcLength        IGcadDimArcLength
#define IAcadDimRadialLarge        IGcadDimRadialLarge
#define IAcadSectionSettings        IGcadSectionSettings
#define IAcadSection        IGcadSection
#define IAcadView        IGcadView
#define IAcadPViewport        IGcadPViewport
#define IAcadGroup        IGcadGroup
#define IAcadGroups        IGcadGroups
#define IAcadDimStyle        IGcadDimStyle
#define IAcadDimStyles        IGcadDimStyles
#define IAcadLayer        IGcadLayer
#define IAcadLayers        IGcadLayers
#define IAcadLineType        IGcadLineType
#define IAcadLineTypes        IGcadLineTypes
#define IAcadXRecord        IGcadXRecord
#define IAcadDictionary        IGcadDictionary
#define IAcadDictionaries        IGcadDictionaries
#define IAcadRegisteredApplication        IGcadRegisteredApplication
#define IAcadRegisteredApplications        IGcadRegisteredApplications
#define IAcadTextStyle        IGcadTextStyle
#define IAcadTextStyles        IGcadTextStyles
#define IAcadUCS        IGcadUCS
#define IAcadUCSs        IGcadUCSs
#define IAcadViews        IGcadViews
#define IAcadViewport        IGcadViewport
#define IAcadViewports        IGcadViewports
#define IAcadPlotConfigurations        IGcadPlotConfigurations
#define IAcadSectionManager        IGcadSectionManager
#define IAcadMaterial        IGcadMaterial
#define IAcadMaterials        IGcadMaterials
#define IAcadAttributeReference        IGcadAttributeReference
#define IAcadDatabase        IGcadDatabase
#define IAcadBlock        IGcadBlock
#define IAcadModelSpace        IGcadModelSpace
#define IAcadLayout        IGcadLayout
#define IAcadPaperSpace        IGcadPaperSpace
#define IAcadBlocks        IGcadBlocks
#define IAcadLayouts        IGcadLayouts
#define IAcadApplication        IGcadApplication
#define IAcadPlot        IGcadPlot
#define IAcadSelectionSet        IGcadSelectionSet
#define IAcadSelectionSets        IGcadSelectionSets
#define IAcadDocument        IGcadDocument
#define IAcadPreferencesFiles        IGcadPreferencesFiles
#define IAcadPreferencesDisplay        IGcadPreferencesDisplay
#define IAcadPreferencesOpenSave        IGcadPreferencesOpenSave
#define IAcadPreferencesOutput        IGcadPreferencesOutput
#define IAcadPreferencesSystem        IGcadPreferencesSystem
#define IAcadPreferencesUser        IGcadPreferencesUser
#define IAcadPreferencesDrafting        IGcadPreferencesDrafting
#define IAcadPreferencesSelection        IGcadPreferencesSelection
#define IAcadPreferencesProfiles        IGcadPreferencesProfiles
#define IAcadPreferences        IGcadPreferences
#define IAcadDocuments        IGcadDocuments
#define IAcadState        IGcadState
#define IAcadMenuGroups        IGcadMenuGroups
#define IAcadMenuGroup        IGcadMenuGroup
#define IAcadPopupMenus        IGcadPopupMenus
#define IAcadPopupMenu        IGcadPopupMenu
#define IAcadPopupMenuItem        IGcadPopupMenuItem
#define IAcadMenuBar        IGcadMenuBar
#define IAcadToolbars        IGcadToolbars
#define IAcadToolbar        IGcadToolbar
#define IAcadToolbarItem        IGcadToolbarItem
#define IAcadShadowDisplay 	    IGcadShadowDisplay

#define ACAD_ANGLE GCAD_ANGLE
#define ACAD_DISTANCE GCAD_DISTANCE
#define ACAD_COLOR GCAD_COLOR
#define ACAD_LAYER GCAD_LAYER
#define ACAD_LWEIGHT GCAD_LWEIGHT
#define ACAD_LTYPE GCAD_LTYPE
#define ACAD_NULL GCAD_NULL
#define ACAD_POINT GCAD_POINT
#define ACAD_NOUNITS GCAD_NOUNITS