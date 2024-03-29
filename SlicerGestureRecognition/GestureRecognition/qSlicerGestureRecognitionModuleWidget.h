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

#ifndef __qSlicerGestureRecognitionModuleWidget_h
#define __qSlicerGestureRecognitionModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerGestureRecognitionModuleExport.h"
#include "vtkMRMLLinearTransformNode.h"

class qSlicerGestureRecognitionModuleWidgetPrivate;
class vtkMRMLNode;
class vtkMRMLLinearTransformNode;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_GESTURERECOGNITION_EXPORT qSlicerGestureRecognitionModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerGestureRecognitionModuleWidget(QWidget *parent=0);
  virtual ~qSlicerGestureRecognitionModuleWidget();


public slots:

	void OnPredictButtonClicked();


protected:
  QScopedPointer<qSlicerGestureRecognitionModuleWidgetPrivate> d_ptr;

  virtual void setup();

private:
  Q_DECLARE_PRIVATE(qSlicerGestureRecognitionModuleWidget);
  Q_DISABLE_COPY(qSlicerGestureRecognitionModuleWidget);
};

#endif
