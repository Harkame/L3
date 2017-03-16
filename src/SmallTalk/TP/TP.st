Object subclass: #NameOfSubclass
	instanceVariableNames: ''
	classVariableNames: 'a_values'
	poolDictionaries: ''
	category: 'TP1'!

Object subclass: #Pile
	instanceVariableNames: 'a_size a_values a_index'
	classVariableNames: ''
	poolDictionaries: ''
	category: 'TP1'!
!Pile commentStamp: 'Pile 3/8/2017 11:03' prior: 0!
isEmpty
	^ true!


!Pile methodsFor: 'initialize' stamp: 'Pile 3/15/2017 10:54'!
initialize
	self initialize: 10.! !

!Pile methodsFor: 'initialize' stamp: 'Pile 3/8/2017 11:48'!
initialize: p_size
	a_index  := 0.
	a_size   := p_size.
	a_values := Array new: a_size.! !


!Pile methodsFor: 'class methods' stamp: 'Pile 3/15/2017 11:45'!
new: p_size
	^ super self initialize:p_size.! !

!Pile methodsFor: 'class methods' stamp: 'Pile 3/15/2017 10:46'!
new
	^ super self initialize:10.! !


!Pile methodsFor: 'accessing' stamp: 'Pile 3/8/2017 12:09'!
push: p_value
	self isFull
		ifTrue:
		[
			self fullStack
		]
		ifFalse:
		[ 
			a_index  := a_index + 1.
			a_values at: a_index put: p_value
		]! !

!Pile methodsFor: 'accessing' stamp: 'Pile 3/8/2017 12:12'!
fullStack
	Transcript show: 'Empty'.! !

!Pile methodsFor: 'accessing' stamp: 'Pile 3/8/2017 12:10'!
emptyStack
	^ a_index == 0! !

!Pile methodsFor: 'accessing' stamp: 'Pile 3/8/2017 12:05'!
isFull
	^ a_index == a_size! !

!Pile methodsFor: 'accessing' stamp: 'Pile 3/8/2017 12:05'!
size
	^ a_size! !

!Pile methodsFor: 'accessing' stamp: 'Pile 3/15/2017 12:07'!
pop
	a_index == 0
	
	ifTrue:
	[
		^ nil.
	];

	ifFalse: 
	[
		^ a_values at: a_index.
	].! !

!Pile methodsFor: 'accessing' stamp: 'Pile 3/8/2017 11:51'!
isEmpty
	^ a_index == a_size! !

"-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- "!

Pile class
	instanceVariableNames: 'a_size'!

!Pile class methodsFor: 'as yet unclassified' stamp: 'Pile 3/8/2017 10:58'!
initialize: pParam
	a_size := pParam! !

!Pile class methodsFor: 'as yet unclassified' stamp: 'Pile 3/8/2017 10:52'!
canMatchMethod: aCollection 
	self shouldBeImplemented.! !


Pile subclass: #PileType
	instanceVariableNames: 'type'
	classVariableNames: ''
	poolDictionaries: ''
	category: 'TP1'!
