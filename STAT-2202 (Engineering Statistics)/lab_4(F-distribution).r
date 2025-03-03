# Lab 4: Simulation of F-Distributed Data and Its Relationship with χ2-Distributions								
								
# Parameters								
df1 <- 5  # Numerator degrees of freedom
df2 <- 10  # Denominator degrees of freedom
N_sim <- 1000  # Number of simulations

# Generate F-distributed data								
set.seed(123)  # Ensures reproducibility
chi2_1 <- rchisq(N_sim, df = df1)  # Generate Chi-Squared data with df1
chi2_2 <- rchisq(N_sim, df = df2)  # Generate Chi-Squared data with df2
f_data <- (chi2_1 / df1) / (chi2_2 / df2)  # Compute F-distributed values
					
# Graphical Output								
par(mfrow = c(2, 2))	# Set layout: 2 rows, 2 columns							
								
# Histogram								
hist(f_data, breaks = 30, col = "lightblue", probability = TRUE, main = "F-Distribution", xlab = "Value", border = "white")								
curve(df(x, df1 = df1, df2 = df2), add = TRUE, col = "red", lwd = 2)								
								
# Density plot								
plot(density(f_data), col = "blue", lwd = 2, main = "Density Plot", xlab = "Value")								
curve(df(x, df1 = df1, df2 = df2), add = TRUE, col = "red", lwd = 2)								
								
# Q-Q plot								
qqplot(qf(ppoints(N_sim), df1 = df1, df2 = df2), f_data, main = "Q-Q Plot for F-Distribution", col = "blue", xlab = "Theoretical Quantiles", ylab = "Sample Quantiles")								
abline(0, 1, col = "red", lwd = 2)								
								
# Boxplot								
boxplot(f_data, col = "lightgreen", main = "Boxplot of F-Distributed Data", ylab = "Value")								
# The boxplot shows the spread and skewness of the F-distributed data.
# Since the F-distribution is right-skewed, the upper whisker is typically longer.