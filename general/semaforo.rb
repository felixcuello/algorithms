
class Semaphore
  def initialize(states, semaphores)
    @states = states
    @semaphores = semaphores
    @is_running = true    # maybe we can set this to false if the semaphore has to be repaired
    @is_emergency = false # this is when we are having an emergency
    @epoch = 0            # this is the number of times the semaphore has ticked
  end

  def show(semaphore_id)
    puts "[#{@epoch}] Semaphore #{semaphore_id} = #{@states[@semaphores[semaphore_id]]}"
  end

  def is_running?
    @is_running
  end

  def tick
    @epoch += 1
    semaphore_count = @semaphores.count
    states_count = @states.length
    semaphore_count.times do |i|
      @semaphores[i] += 1                # We increase the pointer to the next state
      @semaphores[i] %= states_count     # We turn around the states when we reach the end
    end

    set_emergency_mode if @epoch == 5
    unset_emergency_mode if @epoch == 10
  end

  def set_emergency_mode
    @saved_states = @states
    @saved_semaphores = @semaphores
    @states = " Y"
    @semaphores = Array.new(@semaphores.count, 0)
    @is_emergency = true
  end

  def unset_emergency_mode
    @states = @saved_states
    @semaphores = @saved_semaphores
    @is_emergency = false
  end

  def is_emergency?
    @is_emergency
  end
end


semaphore = Semaphore.new('GGGGGGGGYYRRRRRRRRRR', [0, 10])

while semaphore.is_running?
  semaphore.show(0)
  semaphore.show(1)
  semaphore.tick
  sleep 1
end
