/*****************************************************************************
*                                                                            *
*                     SOFTING Industrial Automation GmbH                     *
*                          Richard-Reitzner-Allee 6                          *
*                                D-85540 Haar                                *
*                        Phone: ++49-89-4 56 56-0                            *
*                          Fax: ++49-89-4 56 56-3 99                         *
*                                                                            *
*                            SOFTING CONFIDENTIAL                            *
*                                                                            *
*                     Copyright (C) SOFTING IA GmbH 2016                     *
*                             All Rights Reserved                            *
*                                                                            *
* NOTICE: All information contained herein is, and remains the property of   *
*   SOFTING Industrial Automation GmbH and its suppliers, if any. The intel- *
*   lectual and technical concepts contained herein are proprietary to       *
*   SOFTING Industrial Automation GmbH and its suppliers and may be covered  *
*   by German and Foreign Patents, patents in process, and are protected by  *
*   trade secret or copyright law. Dissemination of this information or      *
*   reproduction of this material is strictly forbidden unless prior         *
*   written permission is obtained from SOFTING Industrial Automation GmbH.  *
******************************************************************************
******************************************************************************
*                                                                            *
* PROJECT_NAME             OPC UA C++ Toolkit                                *
*                                                                            *
* VERSION                  5.52.0                                            *
*                                                                            *
* DATE                     26.09.2016                                        *
*                                                                            *
*****************************************************************************/

#ifndef SERVERAGGREGATEFUNCTION_H
#define SERVERAGGREGATEFUNCTION_H
#if TB5_HISTORY
#include "Base.h"
#include "Enums.h"
#include "ServerObject.h"

namespace SoftingOPCToolbox5
{
	namespace Server
	{
		/*! This class represents an aggregate function (e.g. 'Average'). Servers should create an
		* AggregateFunction object for every aggregate function they support. */
		class TBC_EXPORT AggregateFunction
			: public Object
		{
		public:
			/*! Constructs a new AggregateFunction instance */
			static ObjectPointer<AggregateFunction> create();

			/*! Constructs a new AggregateFunction instance with mandatory attributes */
			static ObjectPointer<AggregateFunction> create(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const ILocalizedText& description);

			/*! @deprecated		Please use AggregateFunction::create() to construct an instance of this type.
			*					This constructor will be made 'protected' in future versions of this product.
			*
			* Default constructor. */
			AggregateFunction();

			/*! Constructor that shall be used by derived classes whose instances are created by the Creator object factory */
			AggregateFunction(TBHandle otbHandle);

		protected:
			/*! Constructs a new AggregateFunction instance with mandatory attributes. */
			AggregateFunction(const INodeId& nodeId,
				const ILocalizedText& displayName,
				const IQualifiedName& browseName,
				const ILocalizedText& description);

		public:
			/*! Destructor */
			virtual ~AggregateFunction();

			/////////////////////////////////////////////////////////////////////////
			// Static Methods of class AggregateFunction
			/////////////////////////////////////////////////////////////////////////

			/*! Factory method for creating an aggregate function object for the 'Interpolative' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createInterpolativeFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Average' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createAverageFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'TimeAverage' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createTimeAverageFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'TimeAverage2' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createTimeAverage2FunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Total' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createTotalFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Total2' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createTotal2FunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Minimum' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createMinimumFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Maximum' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createMaximumFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'MinimumActualTime' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createMinimumActualTimeFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'MaximumActualTime' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createMaximumActualTimeFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Range' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createRangeFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Minimum2' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createMinimum2FunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Maximum2' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createMaximum2FunctionObject();

			/*! Factory method for creating an aggregate function object for the 'MinimumActualTime2' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createMinimumActualTime2FunctionObject();

			/*! Factory method for creating an aggregate function object for the 'MaximumActualTime2' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createMaximumActualTime2FunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Range2' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createRange2FunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Count' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createCountFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'DurationInStateZero' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createDurationInStateZeroFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'DurationInStateNonZero' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createDurationInStateNonZeroFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'NumberOfTransitions' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createNumberOfTransitionsFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Start' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createStartFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'End' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createEndFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'Delta' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createDeltaFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'StartBound' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createStartBoundFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'EndBound' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createEndBoundFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'DeltaBounds' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createDeltaBoundsFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'DurationGood' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createDurationGoodFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'DurationBad' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createDurationBadFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'PercentGood' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createPercentGoodFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'PercentBad' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createPercentBadFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'WorstQuality' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createWorstQualityFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'WorstQuality2' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createWorstQuality2FunctionObject();

			/*! Factory method for creating an aggregate function object for the 'AnnotationCount' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createAnnotationCountFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'StandardDeviationSample' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createStandardDeviationSampleFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'VarianceSample' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createVarianceSampleFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'StandardDeviationPopulation' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createStandardDeviationPopulationFunctionObject();

			/*! Factory method for creating an aggregate function object for the 'VariancePopulation' aggregate.
			* The method returns NULL, if the node already exists in the address space */
			static ObjectPointer<AggregateFunction> createVariancePopulationFunctionObject();

		private:
			/*! Forbid use assignment operator */
			AggregateFunction& operator=(const AggregateFunction&);
			/*! Forbid use of copy constructor */
			AggregateFunction(const AggregateFunction&);
		};
		typedef ObjectPointer<AggregateFunction> AggregateFunctionPtr;
		typedef ObjectPointer<const AggregateFunction> AggregateFunctionConstPtr;

	} // end Server namespace
} // toolbox namespace end

#endif
#endif	// SERVERAGGREGATEFUNCTION_H
