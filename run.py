
from COVID19.model import Model, Parameters
import COVID19.simulation as simulation
import pandas as pd

input_params = pd.read_csv('./tests/data/baseline_parameters.csv')
input_households = pd.read_csv('./tests/data/baseline_household_demographics.csv')

print(input_params)
print(input_households)

params = Parameters(
    input_param_file="./tests/data/baseline_parameters.csv",
    param_line_number=1,
    output_file_dir="./data_test",
    input_households="./tests/data/baseline_household_demographics.csv"
)
params.set_param( "n_total", 10000)
params.set_param( "app_turn_on_time", 10)

model = simulation.COVID19IBM(model = Model(params))
sim   = simulation.Simulation(env = model, end_time = 100 )
sim.steps( 1000 )
print( pd.DataFrame.from_dict(sim.results) )     
