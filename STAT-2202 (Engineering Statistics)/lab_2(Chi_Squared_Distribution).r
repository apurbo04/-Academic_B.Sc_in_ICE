# Lab 2: Generation and Analysis of χ2-Distributed Data								
								
# Parameters								
k <- 5  # Degrees of freedom
N_sim <- 1000  # Number of simulations
															
# Generate chi-squared data								
set.seed(123)								
chi2_data <- rchisq(N_sim, df = k)
# set.seed(123) ensures reproducibility, meaning running the code multiple times will yield the same random numbers.								
rchisq(N_sim, df = k) 
# generates 1000 random numbers from a 𝜒2 distribution with 5 degrees of freedom.
								
# Compute mean and variance								
mean_chi2 <- mean(chi2_data)  # Compute mean
var_chi2 <- var(chi2_data)  # Compute variance	

print(paste("Mean:", mean_chi2))								
print(paste("Variance:", var_chi2))			
# print(): Displays the computed mean and variance.
# paste("Mean:", mean_chi2): Combines text and numerical values into a readable output.					
								
# Graphical Output								
par(mfrow = c(1, 3))	
# Set plotting layout to 1 row, 3 columns							
								
# Histogram								
hist(chi2_data, breaks = 30, col = "lightblue", probability = TRUE, main = "Chi-Squared Distribution", xlab = "Value", border = "white")								
# lots a histogram with density on the y-axis.
curve(dchisq(x, df = k), add = TRUE, col = "red", lwd = 2)								
# overlays the theoretical χ2 density curve in red.

# Density plot								
plot(density(chi2_data), col = "blue", lwd = 2, main = "Density Plot", xlab = "Value")	
#  creates a smooth density plot of the simulated data.							
curve(dchisq(x, df = k), add = TRUE, col = "red", lwd = 2)
# overlays the theoretical χ2 density function.								
								
# Q-Q plot (Quantile-Quantile Plot)					
qqplot(qchisq(ppoints(N_sim), df = k), chi2_data, main = "Q-Q Plot for Chi-Squared Data", col = "blue", xlab = "Theoretical Quantiles", ylab = "Sample Quantiles")								
abline(0, 1, col = "red", lwd = 2)								
# The Q-Q plot compares the quantiles of our simulated data against the theoretical χ2 quantiles
# If the data follows a χ2 distribution, the points should align along the red diagonal line.

# Expected Theoretical Results
# Mean: Expected to be around E[X]=k=5.
# Variance: Expected to be around Var(X)=2k=10.
# Histogram & Density Plot: Should resemble the theoretical χ2 distribution.
# Q-Q Plot: Should approximately follow a straight line.
