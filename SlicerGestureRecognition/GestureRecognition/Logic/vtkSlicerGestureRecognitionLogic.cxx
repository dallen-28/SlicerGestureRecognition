/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// GestureRecognition Logic includes
#include "vtkSlicerGestureRecognitionLogic.h"

// MRML includes
#include <vtkMRMLScene.h>

// VTK includes
#include <vtkIntArray.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>


// STD includes
#include <cassert>

//----------------------------------------------------------------------------
vtkStandardNewMacro(vtkSlicerGestureRecognitionLogic);

static void func(vtkObject *caller, unsigned long eid, void *clientdata, void *calldata);

//----------------------------------------------------------------------------
vtkSlicerGestureRecognitionLogic::vtkSlicerGestureRecognitionLogic()
{
	/*if (!dtwModel.load(":/Resources/DTWModel.grt"))
	{
		vtkErrorMacro("Failed to load DTW Model");
	}*/
	this->transformModifiedCallback = vtkSmartPointer<vtkCallbackCommand>::New();
	this->transformModifiedCallback->SetCallback(func);
}

//----------------------------------------------------------------------------
vtkSlicerGestureRecognitionLogic::~vtkSlicerGestureRecognitionLogic()
{
}

//----------------------------------------------------------------------------
void vtkSlicerGestureRecognitionLogic::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//---------------------------------------------------------------------------
void vtkSlicerGestureRecognitionLogic::SetMRMLSceneInternal(vtkMRMLScene * newScene)
{
  vtkNew<vtkIntArray> events;
  events->InsertNextValue(vtkMRMLScene::NodeAddedEvent);
  events->InsertNextValue(vtkMRMLScene::NodeRemovedEvent);
  events->InsertNextValue(vtkMRMLScene::EndBatchProcessEvent);
  this->SetAndObserveMRMLSceneEventsInternal(newScene, events.GetPointer());
}
void vtkSlicerGestureRecognitionLogic::StartPrediction(vtkMRMLLinearTransformNode* transformNode)
{
	// Attach observer to transformNode

	vtkSmartPointer<vtkMatrix4x4> matr;
	matr = transformNode->GetMatrixTransformFromParent();
	int a = matr->GetElement(0, 3);
	int b = matr->GetElement(1, 3);
	int c = matr->GetElement(2, 3);

	transformNode->AddObserver(vtkMRMLLinearTransformNode::TransformModifiedEvent, this->transformModifiedCallback);


}

static void func(vtkObject *caller, unsigned long eid, void* clientdata, void *calldata)
{
	int a = 1;
}

//-----------------------------------------------------------------------------
void vtkSlicerGestureRecognitionLogic::RegisterNodes()
{
  assert(this->GetMRMLScene() != 0);
}

//---------------------------------------------------------------------------
void vtkSlicerGestureRecognitionLogic::UpdateFromMRMLScene()
{
  assert(this->GetMRMLScene() != 0);
}

//---------------------------------------------------------------------------
void vtkSlicerGestureRecognitionLogic
::OnMRMLSceneNodeAdded(vtkMRMLNode* vtkNotUsed(node))
{
}

//---------------------------------------------------------------------------
void vtkSlicerGestureRecognitionLogic
::OnMRMLSceneNodeRemoved(vtkMRMLNode* vtkNotUsed(node))
{
}
