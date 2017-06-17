/*! \file
 *  \brief Task Graph
 */
#ifndef TASK_GRAPH_H
#define TASK_GRAPH_H

#include "kernel.h"

namespace mango {

/*! @name Task graph definition  */
///@{

/*! \brief A structure type representing a task graph 
 * \note The actual graph structure can be inferred by reading the
 * Kernel and Buffer objects, which include links to the readers
 * and writers.
 */
class TaskGraph {
	public:
 	/*! List of kernels in the TaskGraph */
	std::vector<std::shared_ptr<Kernel>> kernels; 
	/*! List of buffers in the TaskGraph */ 
	std::vector<std::shared_ptr<Buffer>> buffers; 
	/*! List of events in the TaskGraph. Includes also events automatically 
	 * generated by the kernels and buffers.
	 */
	std::vector<std::shared_ptr<Event>> events; 

	TaskGraph(){};

/*! \brief Define a task graph
 * \param lkernels initialization vector of pointers to mango_kernel_t structures
 * representing the kernels in the task graph
 * \param lbuffers initialization vector of pointers to mango_buffer_t structures
 * representing the buffers in the task graph
 * \param levents initialization vector of pointers to mango_event_t structures
 * representing the synchronization events in the task graph
 */
	TaskGraph(
		std::initializer_list<std::shared_ptr<Kernel>> lkernels, 
		std::initializer_list<std::shared_ptr<Buffer>> lbuffers, 
		std::initializer_list<std::shared_ptr<Event>> levents={}){
		for(std::shared_ptr<Event> e : levents) {
			events.push_back(e);
		}		
		for(std::shared_ptr<Kernel> k : lkernels) {
			kernels.push_back(k);
			events.push_back(k->event);
			for(auto e : k->task_events)
				events.push_back(e);
		}
		for(auto b : lbuffers) {
			std::cerr << "Buffer " << b->id << " event " << b->event->id << std::endl;
			buffers.push_back(b);
			events.push_back(b->event);
		}
	};
	
/*! \brief Define a task graph 
 * \param k number of kernels 
 * \param b number of buffers
 * \param e number of events
 * \param ... The variadic parameters must be exactly k mango_kernel_t *, b
 * mango_buffer_t *, and e mango_event_t *, representing the kernels, buffers
 * and events employed in this task graph.
 */
	TaskGraph(int k, int b, int e, ...);

/*! \brief Destroy a task graph
 */
	~TaskGraph(){
			std::cerr << "mango task graph destruction" << std::endl;
			kernels.clear();
			buffers.clear();
			events.clear();
			std::cerr << "end mango task graph destruction" << std::endl;
	};

/*! \brief Destroy a task graph and deregister all of its components
 */
	void destroy();

/*! \brief Add a kernel to the task graph
 * \param kernel The kernel to add
 * \returns The task graph
 */
	TaskGraph & operator+=(std::shared_ptr<Kernel> kernel) { 
		kernels.push_back(kernel); 
		return *this;
	};

/*! \brief Remove a kernel from the task graph
 * \param kernel The kernel to add
 * \returns The task graph
 */
	TaskGraph & operator-=(std::shared_ptr<Kernel> kernel) { 
		kernels.erase(std::remove(kernels.begin(), kernels.end(), kernel));
		return *this;
	};


/*! \brief Add a buffer to the task graph
 * \param buffer The buffer to add
 * \returns The task graph
 */
	TaskGraph & operator+=(std::shared_ptr<Buffer> buffer) { 
		buffers.push_back(buffer);
		return *this;
	};

/*! \brief Remove a buffer from the task graph
 * \param buffer The buffer to add
 * \returns The task graph
 */
	TaskGraph & operator-=(std::shared_ptr<Buffer> buffer) { 
		buffers.erase(std::remove(buffers.begin(), buffers.end(), buffer));
		return *this;
	};

/*! \brief Add a event to the task graph
 * \param event The event to add
 * \returns The task graph
 */
	TaskGraph & operator+=(std::shared_ptr<Event> event) { 
		events.push_back(event);
		return *this;
	};

/*! \brief Remove a event from the task graph
 * \param event The event to add
 * \returns The task graph 
 */
	TaskGraph & operator-=(std::shared_ptr<Event> event) { 
		events.erase(std::remove(events.begin(), events.end(), event));
		return *this;
	};

};
///@}

}
#endif /* TASK_GRAPH_H */