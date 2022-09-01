/*
	1-2

		isRoad -> F

			way Flight

				T1=Flight time(1-2)

		isRoad -> T

			can Flight
				
				way Flight
				
					T1=Flight time(1-2)
				
				way Road

					T2=Road time(1-2)

				ans=min{T1, T2}

			can not Flight

				way Road

					T1=Road time(1-2)
	
	1-3

		isRoad -> F

			2-3 isRoad -> F

				way Flight

					T1=Time at 2 + Flight time(2-3)  // transit

					T2=Flight time(1-3) // direct flight

				ans=min{T1, T2}
			
			2-3 isRoad -> T

				way Road -> T1=Time at 2 + Flight time(2-3)
				
				can Flight

					call 1

						way Flight

							T2=Time at 2 + Flight time(2-3)

							T3=Flight time(1-3)
					
					call 2
						
						way Road -> T4=Time at 2 + Time(2-3)

				ans=min{T1, T2, T3, T4}

		isRoad -> T

			can Flight

				call 1

					way Flight

						T1=Time at 2 + Flight time(2-3)

						T2=Flight time(1-3)
				
				call 2
					
					way Road -> T3=Time at 2 + Time(2-3)

			way Road -> T4=Road Time(1-4)

			ans=min{T1, T2, T3, T4}

	...

	1-n

*/