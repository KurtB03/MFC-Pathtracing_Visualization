namespace dij {
	class Node;

	class Node {
		private:
			int x;
			int y;

			bool is_start;
			bool is_end;

			Node* neigbours[4];
			int neigbour_weights[4];

			int distanz;
			Node* parent;

		public:

			void setNeighbour(Node* n, int index){
				neigbours[index] = n;
			}
			void setNeighbour(Node* n, int index, int weight){
				neigbours[index] = n;
				neigbour_weights[index] = weight;
			}
			void setNeighbourWeight(Node* n, int w){
				int i = 0;
				for(auto ni : neigbours){
					if(ni == n){
						neigbour_weights[i] = w;
						break;
					}
					i++;
				}
			}
			void setParent(Node* n){
				parent = n;
			}

			void setStart(bool s){
				is_start = s;
			}
			void setEnd(bool e){
				is_end = e;
			}

			void removeNeighbour(Node* n){
				for(auto i : neigbours){
					if(i == n){
						n = nullptr;
						setNeighbourWeight(n, 0);
					}
				}
			}



			Node(int x, int y){
				this->x = x;
				this->y = y;

				is_end = false;
				is_start = false;

				parent = nullptr;
				distanz = __INT32_MAX__;

				for(auto i : neigbours){
					i = nullptr;
				}
				for(auto i : neigbour_weights){
					i = 0;
				}
			}
			Node(){
				x = 0;
				y = 0;

				is_end = false;
				is_start = false;

				parent = nullptr;
				distanz = __INT32_MAX__;

				for(auto i : neigbours){
					i = nullptr;
				}
				for(auto i : neigbour_weights){
					i = 0;
				}
			}
			~Node(){
				for(auto i : neigbours){
					i->removeNeighbour(this);
				}
			}
	};



}
